#ifndef CONSTANTS_H
#define CONSTANTS_H



//SIMULATION CONSTANTS
const long SIM_END_TIME (10000);

//NETWORK CONSTANTS
const int N_TOTAL(12500);
const int N_EXCITATORY (N_TOTAL * 0.8);
const int N_INHIBITORY (N_TOTAL * 0.2);

//NEURON CONSTANTS	
const double H (0.1);
const double TAU (20.0);
const double C(1.0);
const double R (TAU / C) ;
const double THR_POT (20.0);
const double RESET_POT(0.0);
const double REF_TIME(2.0);     //refractory perios in ms
const double J_AMP_EXCIT (0.1);
const double J_AMP_INHIB (0.5);
const double D (1.5);
const double V_EXT (0.02);
const int D_STEPS(D / H);
const int C_EXCITATORY (N_EXCITATORY * 0.1);
const int C_INHIBITORY (N_INHIBITORY * 0.1);
const int C_TOTAL (C_EXCITATORY + C_INHIBITORY);


#endif