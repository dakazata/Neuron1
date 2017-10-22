#include "Network.hpp"

#include <vector>

//Constructor
Network::Network()
	:neurons_()
{}
		
//add a neuron to the vector neurons_
void Network::addNeuron(Neuron* neuron)
{
	neurons_.push_back(neuron);
}

std::vector<Neuron*> Neuron::getNeurons() const
{
	return neurons_;
}

//update
void Network::update(int time, double current)
{
	bool spike(false);
	int neuron_counter(1);
	
	//for every neuron in the network
	for (auto n: neurons_)
	{
		if (n->getConnections.empty())
		{
			//if the neuron has no connections we input a current of 0
			spike = n->update(time , 0.0);
		} 
		else
		{
			spike = n->update(time, current);
		}
		
		if (spike)
		{
			//ajouter spike au buffer de neurones connectes
			for (auto& n : connections_)
			{
				n.receive(time);
			}
		}
	}
}
