cmake_minimum_required(VERSION 3.21)
project(simulated_annealing)

set(CMAKE_CXX_STANDARD 11)

add_executable(simulated_annealing RandomNumberGenerator.h main.cpp singleMachine.h simulatedAnnealing.h)
