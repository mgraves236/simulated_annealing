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
	for (int i = 0; i < n; i++) {
		std::cout << schedule[i] << "\t";
	}
	std::shuffle(schedule, schedule + n, std::mt19937(std::random_device()()));
	std::cout << "\n";
	for (int i = 0; i < n; i++) {
		std::cout << schedule[i] << "\t";
	}
	std::cout << "\n";


	tardinessSum(array, schedule, n);



}

#endif //SIMULATED_ANNEALING_SIMULATEDANNEALING_H
