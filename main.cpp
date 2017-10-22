#include <iostream>
#include <fstream>
#include "neuron.hpp"

using namespace std;

int main()
{
	const double H(0.1);
	int simulation_time(0); 		//bouge en pas 
	int t_stop(500);				//in ms
	double current(0);
	int a, b; 						//constants time interval
		
	cout << "Start of time interval: " << endl;
	cin >> a;
	cout << "End of time interval: " << endl;
	cin >> b;
	cout << "What is the external current? " << endl;
	cin >> current;
	
		
	//Creation de neurone
	Neuron n;
	
	//Creation of write file
	ofstream textfile;
	textfile.open("Membrane_Potentials.txt");
	textfile << "Membrane Potentials : " << endl;
	
	while (simulation_time * H < t_stop)    //calculation in ms not steps
	{		
		//if we are inside the time interval given we set the neurons current
		if (simulation_time*H >= a or simulation_time*H < b)
		{
			n.setCurrent(current);
		}
		else
		{
			n.setCurrent(0.0);
		}
		
		bool spike = n.update();
		
		//si on a un spike pendant le update
		if (spike)
		{
			//on ajoute le spike time aux vecteur dans la neurone
			n.addSpikeTime(simulation_time*H);
			//on affiche le temps dans le fichier externe
			textfile << "Spike time: " << simulation_time << endl;
		}
		
		simulation_time++;
	}
	
	textfile.close();
}