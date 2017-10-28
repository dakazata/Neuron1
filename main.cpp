#include <iostream>
#include <fstream>
#include <cassert>
#include "Neuron.hpp"
#include "Network.hpp"
#include "Buffer.hpp"
#include "Constants.hpp"

using namespace std;

int main()
{
	int simulation_time(0); 		//bouge en pas 			//in steps
	double current(0);
	int a, b; 						//constants time interval
		
	cout << "Start of time interval: " << endl;
	cin >> a;
	cout << "End of time interval: " << endl;
	cin >> b;
	
	assert (a >= 0 and a <= b);

	//Creation des network
	Network network(N_TOTAL);
	
	network.makeTargets();
		
	
	//Creation of write file
	//ofstream textfile1;
	ofstream textfile2;
	//textfile1.open("Membrane_Potentials.txt");
	textfile2.open("Spike_Times.txt");
	
	//write titles on external files
	//textfile1 << "Membrane Potentials : " << endl;
	textfile2 << "Spike Times : " << endl;
	
	while (simulation_time < SIM_END_TIME)    //calculation in steps
	{		
		//if we are inside the time interval given we set the neurons current
		if (simulation_time*H >= a or simulation_time*H < b)
		{
			network.setExternalCurrent(current);
			
			network.update(simulation_time, 1 , 0.0);
		}
		else
		{
			network.setExternalCurrent(0.0);
		}
		
		simulation_time++;
	}
	
	//textfile1.close();
	textfile2.close();

}