cmake_minimum_required (VERSION 2.6)
project (Neuron)

set (CMAKE_CXX_FLAGS "-W -Wall -pedantic -std=c++11")

enable_testing()
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


add_executable (neuron Neuron.cpp main.cpp Network.cpp Buffer.cpp)
add_executable (neurontest NeuronTests.cpp Neuron.cpp Buffer.cpp)

target_link_libraries(neurontest gtest gtest_main)
add_test(neurontest neurontest)