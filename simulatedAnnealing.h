//
// Created by Magda on 10.05.2023.
//

#ifndef SIMULATED_ANNEALING_SIMULATEDANNEALING_H
#define SIMULATED_ANNEALING_SIMULATEDANNEALING_H

#include <algorithm>
#include <random>
#include "singleMachine.h"

int* simulatedAnnealing(int** array, int n) {
	// randomize first permutation
	int schedule[n];
	for (int i = 0; i < n; i++) {
		schedule[i] = i;
	}
//	for (int i = 0; i < n; i++) {
//		std::cout << schedule[i] << "\t";
//	}
	// initial solution is a random permutation
	std::shuffle(schedule, schedule + n, std::mt19937(std::random_device()()));
//	std::cout << "\n";
//	for (int i = 0; i < n; i++) {
//		std::cout << schedule[i] << "\t";
//	}
//	std::cout << "\n";
	float T = 10;
	int best = 	tardinessSum(array, schedule, n);

	// stop condition
	int iterMax = 100;
	int	iter = 0;

	int* temp;
	temp = new int[n];
	while (iter < iterMax) {
		// get random solution from the neighbourhood

		iter++;
	}



}

#endif //SIMULATED_ANNEALING_SIMULATEDANNEALING_H
