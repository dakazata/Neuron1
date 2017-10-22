#ifndef NEURON_H
#define NEURON_H

#include <vector>

class Neuron
{
	private:	
		const double h_;
		const double tau_;
		const double R_ ;
		const double thr_pot_;
		const double ref_time_;
		double c1_, c2_; 				//for the membrane equation
		
		double memb_pot_;
		int nb_spikes_;
		double i_ext_;
		bool refractory_;
		double break_time_;
		
		std::vector<double> spike_times_; 		//contains time(t*h) of spikes
	

	public:
		Neuron(); 			//constructeur	
		~Neuron() = default;	//destructeur
		
		double getMembranePotential() const;
		int getNbSpikes() const;
		std::vector<double> getSpikeTimes() const;
		
		void setCurrent(double);
		void setMembranePotential(double);
		
		bool isRefractory();
		
		double solveMembEquation();
		
		void addSpikeTime(double time);
		
		bool update(); 		//methode appele a chaque pas de temps dans le main
		
	

	
	
};

#endif
