#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include "Neuron.hpp"
#include "Constants.hpp"

class Network
{
	private:
		int nb_neurons_;
		std::vector<Neuron*> neurons_; 		//stores neurons in the network
		std::vector<Neuron*> excit_neurons_;
		std::vector<Neuron*> inhib_neurons_;
		
	public:
		//Constructor
		Network(int totalneurons);
		
		//Destructor
		~Network() = default;
		
		//add a neuron to the vector neurons_
		//void addNeuron(Neuron* neuron);
		
		//gets vector of neurons
		std::vector<Neuron*> getExcitNeurons() const;
		//std::vector<Neuron*> getInhibNeurons() const;
		
		void makeTargets();
		
		void setExternalCurrent(double current);
		
		//update
		void update(unsigned int time, unsigned int steps, double current);
};


#endif

