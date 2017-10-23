cmake_minimum_required (VERSION 2.6)
project (Neuron)

set (CMAKE_CXX_FLAGS "-W -Wall -pedantic -std=c++11")
add_executable (neuron Neuron.cpp main.cpp Network.cpp Buffer.cpp)