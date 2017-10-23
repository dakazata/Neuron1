#include "Network.hpp"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//Constructor
Network::Network()
	:neurons_()
{}
		
//add a neuron to the vector neurons_
void Network::addNeuron(Neuron* neuron)
{
	neurons_.push_back(neuron);
}

std::vector<Neuron*> Network::getNeurons() const
{
	return neurons_;
}

//update
void Network::update(int time, double current)
{
	ofstream textfile1, textfile2;
	textfile1.open("Membrane_Potentials.txt", std::ios_base::app);
	textfile2.open("Spike_Times.txt", std::ios_base::app);	
	
	bool spike(false);
	int neuron_counter(0);
	
	//for every neuron in the network
	for (auto n: neurons_)
	{
		//augmenter the neuron counter . Way of indexing them
		++neuron_counter;
		
		if (n->getConnections().empty())
		{
			//if the neuron has no connections we input a current of 0
			spike = n->update(time , 0.0);
		} 
		else
		{
			spike = n->update(time, current);
		}
		
		textfile1 << "Potential at time " << time*h_ << " of " << neuron_counter << " : " << n->getMembranePotential() << endl;
		
		if (spike)
		{
			cout << "SPIKE happening" << endl;
			//ajouter spike au buffer de neurones connectes
			for (auto& n : neurons_)
			{
				for (auto& c: n->getConnections())
				{
					c->receive(time);
				}
			}
			
			//envoyer le spike signal au fichier externe
			textfile2 << "Spike for neuron " << neuron_counter << " at : " << time * h_ << endl;
		}
		
	}
	
	textfile1.close();
	textfile2.close();
}