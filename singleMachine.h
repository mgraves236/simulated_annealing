//
// Created by Magda on 10.05.2023.
//
#ifndef SIMULATED_ANNEALING_SINGLEMACHINE_H
#define SIMULATED_ANNEALING_SINGLEMACHINE_H

#include "RandomNumberGenerator.h"
#include <iostream>


void printInstance(int** array, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << array[i][j] << "\t";
		}
		std::cout << '\n';
	}
}

int** initialize_instance(int seed, int n) {
	RandomNumberGenerator random = RandomNumberGenerator(seed);
	int** jobs;
	jobs = new int* [n];
	for (int i = 0; i < n ; i++ ) {
		jobs[i] = new int[3];
	}
	for (int i = 0; i < n ; i++ ) {
		jobs[i][0] = random.nextInt(1, 30); // p_i duration
		jobs[i][1] = random.nextInt(1, 30); // w_i weight
	}
	int S = 0;
	for (int i = 0; i < n ; i++ ) {
		S += jobs[i][0];
	}
	for (int i = 0; i < n ; i++ ) {
		jobs[i][2] = random.nextInt(1, S);
	}

	return jobs;
}


#endif //SIMULATED_ANNEALING_SINGLEMACHINE_H
