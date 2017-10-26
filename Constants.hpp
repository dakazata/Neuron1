#ifndef CONSTANTS_H
#define CONSTANTS_H

//NEURON CONSTANTS	
const double H (0.1);
const double TAU (20.0);
const double C(1.0);
const double R (TAU / C) ;
const double THR_POT (20.0);
const double RESET_POT(0.0);
const double REF_TIME(2.0);
const double J_AMP (0.1);
const double D (1.5);
const int D_STEPS(D / H);


//SIMULATION CONSTANTS
const long SIM_END_TIME (10000);
#endif