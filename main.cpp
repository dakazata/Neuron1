#include <iostream>
#include <fstream>
#include "Neuron.hpp"
#include "Network.hpp"
#include "Buffer.hpp"

using namespace std;

int main()
{
	const double H(0.1);
	int simulation_time(0); 		//bouge en pas 
	int t_stop(10000);				//in steps
	double current(0);
	int a, b; 						//constants time interval
		
	cout << "Start of time interval: " << endl;
	cin >> a;
	cout << "End of time interval: " << endl;
	cin >> b;
	cout << "What is the external current? " << endl;
	cin >> current;

	//Creation des neurones
	Network network;
	Neuron n1;
	Neuron n2;
	
	//add neurons to network
	network.addNeuron(&n1);
	network.addNeuron(&n2);
	
	//connect neuron
	n1.addConnection(&n2);
	
	//Creation of write file
	ofstream textfile1;
	ofstream textfile2;
	textfile1.open("Membrane_Potentials.txt");
	textfile2.open("Spike_Times.txt");
	
	//write titles on external files
	textfile1 << "Membrane Potentials : " << endl;
	textfile2 << "Spike Times : " << endl;
	
	while (simulation_time < t_stop)    //calculation in steps
	{		
		//if we are inside the time interval given we set the neurons current
		if (simulation_time*H >= a or simulation_time*H < b)
		{
			for (auto& n: network.getNeurons())
			{
				n->setCurrent(current);
			}
			
			network.update(simulation_time, current);
		}
		else
		{
			for (auto& n: network.getNeurons())
			{
				n->setCurrent(0.0);
			}
		}
		
		simulation_time++;
	}
	
	textfile1.close();
	textfile2.close();
}