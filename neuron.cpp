#include <iostream>
#include "neuron.hpp"
#include <cmath>
//#include <cassert>

using namespace std;

Neuron::Neuron()
	:h_(0.1),
	tau_(20.0),
	R_ (20.0),
	thr_pot_(20),
	ref_time_(0.2),
	 memb_pot_(0.0),
	 nb_spikes_(0),
	 i_ext_(0.0),
	 refractory_(false),
	 break_time_(0.0),
	 spike_times_()	
{
	c1_ = exp(- h_ /tau_);
	c2_= R_*(1.0 - c1_);
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
	return c1_ * memb_pot_ + i_ext_ * c2_;
}

void Neuron::addSpikeTime(double time)
{
	spike_times_.push_back(time);
}

///*Si la neurone is refractory we set its potential to 0
///else if it surpasses the threshold potential we set a spike
///we save this spike time in the vectors spike_times_, we augment the 
///nb_spikes, and we set the variable t_spike to the current time;

bool Neuron::update()
{
	bool spike(false);
	
	if (refractory_)
	{
		setMembranePotential(0.0);
		//si on a depasse le temps ou il devait rester refractory on le remets
		if (break_time_ <= 0.0)
		{
			refractory_ = false;
			break_time_ = ref_time_;
		}
		
		break_time_ -= h_;
	}
	else if (memb_pot_ > thr_pot_)
	{
		nb_spikes_++;
		spike = true;
		refractory_ = true;
	}
	
	memb_pot_ = solveMembEquation();	
	
	return spike;
}
