#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include "Neuron.hpp"

const double h_ = 0.1;

class Network
{
	private:
		std::vector<Neuron*> neurons_; 		//stores neurons in the network
	
	public:
		//Constructor
		Network();
		
		//Destructor
		~Network() = default;
		
		//add a neuron to the vector neurons_
		void addNeuron(Neuron* neuron);
		
		//gets vector of neurons
		std::vector<Neuron*> getNeurons() const;
		
		//getter des neurones
		//Neuron getNeuron
		
		//update
		void update(int time, double current);
};

#endif