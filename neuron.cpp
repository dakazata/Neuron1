#include <iostream>
#include "Neuron.hpp"
#include <cmath>
#include <cassert>

using namespace std;

Neuron::Neuron()
	:memb_pot_(0.0),
	nb_spikes_(0),
	i_ext_(0.0),
	refractory_(false),
	break_time_(0.0),
	clock_(0),
	spike_times_(),
	connections_(),
	buffer_()
{
	assert(TAU != 0);
	c1_ = exp(- H / TAU);
	c2_= R*(1.0 - c1_);
}

double Neuron::getMembranePotential() const
{
	return memb_pot_;
}

int Neuron::getNbSpikes() const
{
	return nb_spikes_;
}

vector<double> Neuron::getSpikeTimes() const
{
	return spike_times_;
}

vector<Neuron*> Neuron::getConnections() const
{
	return connections_;
}

Buffer Neuron::getBuffer() const
{
	return buffer_;
}
		
void Neuron::setCurrent(double current)
{
	i_ext_ = current;
}

void Neuron::setMembranePotential(double pot)
{
	memb_pot_ = pot;
}
		
bool Neuron::isRefractory()
{
	return refractory_;
}

double Neuron::solveMembEquation()
{
	return (c1_ * memb_pot_) + (i_ext_ * c2_);
}

void Neuron::addSpikeTime(double time)
{
	spike_times_.push_back(time);
}

void Neuron::addConnection(Neuron* target)
{
	assert(target != nullptr);
	connections_.push_back(target);
}

void Neuron::receive(unsigned long time)
{
	buffer_.addJ(time);
}

///*Si la neurone is refractory we set its potential to 0
///else if it surpasses the threshold potential we set a spike
///we save this spike time in the vectors spike_times_, we augment the 
///nb_spikes, and we set the variable t_spike to the current time;

bool Neuron::update(unsigned int time, unsigned int steps, double current)
{
	bool spike(false);
	clock_ = time;
	unsigned int t_stop = clock_ + steps;
	i_ext_ = current;
	
	while (clock_ < t_stop)
	{
		if (refractory_)
		{
			setMembranePotential(RESET_POT);
			//si on a depasse le temps ou il devait rester refractory on le remets
			if (break_time_ <= 0.0)
			{
				refractory_ = false;
				break_time_ = REF_TIME;
			}
		
			break_time_ -= H;
		}
		else if (memb_pot_ > THR_POT)
		{
			addSpikeTime(clock_);
			nb_spikes_++;
			spike = true;
			refractory_ = true;		
		}
	
		setMembranePotential(solveMembEquation() + (buffer_.getJ(time) * J_AMP));
		buffer_.resetValue(time);	

		clock_++;
	}
	
	return spike;
}