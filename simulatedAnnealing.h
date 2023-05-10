//
// Created by Magda on 10.05.2023.
//

#ifndef SIMULATED_ANNEALING_SIMULATEDANNEALING_H
#define SIMULATED_ANNEALING_SIMULATEDANNEALING_H

#include <algorithm>
#include <array>
#include <random>
#include <ctime>
#include "singleMachine.h"
#include "RandomNumberGenerator.h"

struct solution {
	int* schedule;
	int tardinessSum;
};

RandomNumberGenerator random = RandomNumberGenerator(9862486458);


void printSchedule(int* array, int const n) {
	for(int i = 0; i < n; i++) {
		std::cout << array[i] << '\t';
	}
	std::cout << '\n';
}

void copyArray(int* copy, int* org, int const n) {
	for (int i = 0; i < n; i++) {
		copy[i] = org[i];
	}
}

int* randomSwap(int* array, int const n) {
	// make a copy of the array
	int* temp;
	temp = new int[n];
	copyArray(temp, array, n);

	// get two random indexes that will be swapped
	int index1 = random.nextInt(0, n - 1);
	int index2 = random.nextInt(0, n - 1);
//	std::cout << "indeces  " <<  index1 << "     " << index2 << '\n';
	while (index2 ==  index1) {
		index2 = random.nextInt(0, n - 1);
	}
//	std::cout << "indecesp  " <<  index1 << "     " << index2 << '\n';

	// perform swap
	temp[index1] = array[index2];
	temp[index2] = array[index1];

	return temp;
}
// acceptance function
double p(int* array, int* temp, int n, double t, int** matrix) {
	int old = tardinessSum(matrix, array, n);
	int prob = tardinessSum(matrix, array, n);

	float p = exp((- (double) prob - (double) old) / t);
	return p;
}
solution simulatedAnnealing(int** array, int const n) {
	// randomize first permutation
	int schedule[n];
	for (int i = 0; i < n; i++) {
		schedule[i] = i;
	}
	// initial solution is a random permutation
	std::shuffle(schedule, schedule + n, std::mt19937(std::random_device()()));

	double T = 10;
	double alpha = 0.96;
	int best = 	tardinessSum(array, schedule, n);
	int* bestSchedule;
	bestSchedule = new int[n];
	copyArray(bestSchedule, schedule, n);
	std::cout << "best " << best << '\n';

	// stop condition
	int iterMax = 5;
	int	iter = 0;

	int* temp;
	temp = new int[n];
	while (iter < iterMax) {
		// get random solution from the neighbourhood
		temp = randomSwap(schedule, n);
		printSchedule(temp, n);
		int tSum = tardinessSum(array, temp, n);
		std::cout << "T_Sum " << tSum << '\n';
		if (tSum < best) {
			copyArray(schedule, temp, n);
		} else if (p(schedule, temp, n, T, array) >= random.nextFloat(.0,1.0)) {
			copyArray(schedule, temp, n);
		}
		if (tSum < best) {
			best = tSum;
			copyArray(bestSchedule, schedule, n);
		}
		T = alpha * T;
		iter++;
	}
	std::cout << best << "\t";
	printSchedule(bestSchedule, n);
}

#endif //SIMULATED_ANNEALING_SIMULATEDANNEALING_H
