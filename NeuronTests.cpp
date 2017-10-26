#include "gtest/gtest.h"
#include "Neuron.h"
#include <vector>
#include <cmath>

TEST (OneNeuronTest , MembranePotential)
{
	Neuron n;
	double current (1.0);
	
	//One Update
	//should expect exact calculated value 
	n.update(0, 1, current);
	EXPECT_EQ(20.0 * (1.0 - exp(-0.1 / 20.0)) , n.getMembranePotential());
	
	//Several updates
	//should tend to 20 and should not spike
	n.update(0 , 10000 , currenz);
	EXPECT_LT(20.0 n.getMembranePotential());
	EXPECT_EQ(0 . getNbSpikes());
	
}

TEST (OneNeuronTest , SpikeTimes)
{
	Neuron n;
	double current(1.01);
	
	//spike times with 1.01 as i_ext :
	// at 92.4 ms, 186.8 ms, 281,2 ms and 375.6 ms
	
	//update the neuron 3757 times (steps) and check the spike times
	n.update(0 , 3757 , 1.01);
	
	std::vector<double> spike_t = n.getSpikeTimes();
	
	EXPECT_EQ(924 , spike_t[0]);
	EXPECT_EQ(1868 , spike_t[1]);
	EXPECT_EQ(2812 , spike_t[2]);
	EXPECT_EQ(3756 , spike_t[3]);
		
}







int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}