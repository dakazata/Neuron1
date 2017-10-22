#ifndef NEURON_H
#define NEURON_H

#include <vector>
#include "Buffer.hpp"

class Neuron
{
	private:	
		const double h_;
		const double tau_;
		const double C_;
		const double R_ ;
		const double thr_pot_;
		const double ref_time_;
		const double j_amp_;
		const int delay_;
		double c1_, c2_; 				//for the membrane equation
		
		double memb_pot_;
		int nb_spikes_;
		double i_ext_;
		bool refractory_;
		double break_time_;
		unsigned int clock;				//local clock in steps
		
		std::vector<double> spike_times_; 		//contains time(t*h) of spikes
		std::vector<Neuron*> connections_;
		Buffer buffer_;

	public:
		Neuron(); 			//constructeur	
		~Neuron() = default;	//destructeur
		
		double getMembranePotential() const;
		int getNbSpikes() const;
		std::vector<double> getSpikeTimes() const;
		std::vector<Neuron*> getConnections() const;
		Buffer getBuffer() const;
		
		void setCurrent(double);
		void setMembranePotential(double);
		
		bool isRefractory();
		
		double solveMembEquation();
		
		void addSpikeTime(double time);
		
		void addConnection(Neuron* target);
		
		void receive(unsigned long);
		
		bool update(unsigned int time, double current); 		//methode appele a chaque pas de temps dans le main
		
	

	
	
};

#endif
