#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include "Neuron.hpp"
#include "Constants.hpp"

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
		
		void setExternalCurrent(double current);
		
		//update
		void update(unsigned int time, unsigned int steps, double current);
};


#endif