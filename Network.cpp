#include "Network.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <random>

using namespace std;


//Constructor
Network::Network(int totalneurons)
	: nb_neurons_(totalneurons)
{
	
	///remplissage avec neurones excitatoires et inhibitoires
	//boucle se parcout N_EXCIT fois
	for (int i(0) ; i < (nb_neurons_ * 0.?? ; i++)
	{
		Neuron* n = new Neuron("excitatory");
		neurons_.push_back(n);
		excit_neurons_.push_back(n);
	}
	
	//boucle se parcourt N_INHIB fois
	for (int i(0) ; i < (nb_neurons_ * 0.2) ; i++)
	{
		Neuron* n = new Neuron("inhibitory");
		neurons_.push_back(n);
		inhib_neurons_.push_back(n);
	}
}
		
/*
//add a neuron to the vector neurons_
void Network::addNeuron(Neuron* neuron)
{
	assert(neuron != nullptr);
	neurons_.push_back(neuron);
}
*/

std::vector<Neuron*> Network::getExcitNeurons() const
{
	return excit_neurons_;
}
/*
std::vector<Neuron*> Network::getInhibNeurons() const
{
	return inhib_neurons_;
}
* */

void Network::setExternalCurrent(double current)
{
	for (auto& n: neurons_)
	{
		n->setCurrent(current);
	}
}

void Network::makeTargets()
{
	//random generator for excitatory connections
	random_device rdE;
	mt19937 genE(rdE());
	uniform_int_distribution<> disE(0, N_EXCITATORY - 1);
	
	random_device rdI;
	mt19937 genI(rdI());
	uniform_int_distribution<> disI(0, N_INHIBITORY - 1);
	
	//premiere boucle parcourt toutes les neurones 
	for (auto& n : neurons_)
	{
		int nb_excit(0);
		int nb_inhib(0);
		
		while(nb_excit + nb_inhib < C_TOTAL)
		{
			
			int indice = disE(genE);
		
			if (neurons_[indice]->getType() == "excitatory")
			{
				nb_excit++;
				if (!(nb_excit > C_EXCITATORY))
				{
					neurons_[indice]->addTarget(n);
				}
			} 
			else if (neurons_[indice]->getType() == "inhibitory")
			{
				nb_inhib++;
				if (!(nb_inhib > C_INHIBITORY))
				{
					neurons_[indice]->addTarget(n);
				}
			}
		}
		
		assert ((nb_excit + nb_inhib) == 1250);

	}
	
}

//update
void Network::update(unsigned int time, unsigned int steps, double current)
{
	ofstream textfile2;
	//textfile1.open("Membrane_Potentials.txt", std::ios_base::app);
	textfile2.open("Spike_Times.txt", std::ios_base::app);	
	
	bool spike(false);
	int neuron_counter(0);
	unsigned int t_stop = time + steps;
	
	while(time < t_stop)
	{
		//for every neuron in the network
		for (auto n: neurons_)
		{	
			//augmenter the neuron counter . Way of indexing them
			++neuron_counter;
		
			if (n->getTargets().empty())
			{
				//if the neuron has no connections we input a current of 0
				spike = n->update(time , steps,  0.0);
			} 
			else
			{
				spike = n->update(time, steps,  current);
			}
		
			//textfile1 << "Potential at time " << time*H << " of " << neuron_counter << " : " << n->getMembranePotential() << endl;
		
			if (spike)
			{
				cout << "SPIKE happening" << endl;
				//ajouter spike au buffer de neurones connectes
				for (auto& n : neurons_)
				{
					for (auto& c: n->getTargets())
					{
						c->receive(time , n->getType());
					}
				}
			
				//envoyer le spike signal au fichier externe
				textfile2 << "Spike for neuron " << neuron_counter << " at : " << time * H << endl;
			}
		
		}
		
		++time;
	}
	
	//textfile1.close();
	textfile2.close();

}