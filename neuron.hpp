#ifndef NEURON_H
#define NEURON_H

#include <vector>
#include <string>
#include "Buffer.hpp"
#include "Constants.hpp"

class Neuron
{
	private:	
		double c1_, c2_; 				//for the membrane equation
		
		double memb_pot_;
		int nb_spikes_;
		double i_ext_;
		bool refractory_;
		int break_time_;
		unsigned int clock_;				//local clock in steps
		unsigned int t_spike_;
		std::string type_;      ///FAIRE UN ENUM POUR LE TYOPE
		
		std::vector<double> spike_times_; 		//contains time(t*h) of spikes
		//std::vector<int> receiver_connections_;			//contient les indices des neurones dans tableau neurones du network
		std::vector<Neuron*> targets_;		//contient les neurones auxquels il donne un signal
		Buffer buffer_;

	public:
		Neuron(std::string typeneurone = "excitatory", double courant = 0.0); 			//constructeur	
		~Neuron() = default;	//destructeur
		
		double getMembranePotential() const;
		int getNbSpikes() const;
		std::vector<double> getSpikeTimes() const;
		//std::vector<int> getReceiverConnections() const;
		std::vector<Neuron*> getTargets() const;
		Buffer getBuffer() const;
		std::string getType() const;
		
		void setCurrent(double);
		void setMembranePotential(double);
		
		bool isRefractory();
		
		double solveMembEquation();
		
		void addSpikeTime(double time);
		
		void addTarget(Neuron* target);
		
		void receive(unsigned long , std::string);
		
		double calcBackgroundNoise();
		
		void sendSpikes() const;
		
		//void fillExternalConnections();					//push back du vector connections_ avec les connections exterieures avec courant cree au hasard
		
		bool update(unsigned int time, unsigned int steps, double current); 		//methode appele a chaque pas de temps dans le main
		
	
};