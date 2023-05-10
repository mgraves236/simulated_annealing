//
// Created by Magda on 10.05.2023.
//

#ifndef SIMULATED_ANNEALING_SIMULATEDANNEALING_H
#define SIMULATED_ANNEALING_SIMULATEDANNEALING_H

#include <algorithm>
#include <random>
#include <ctime>
#include "singleMachine.h"
#include "RandomNumberGenerator.h"

struct solution {
	int* schedule;
	int tardinessSum;
};

RandomNumberGenerator random = RandomNumberGenerator(9862486458);


void printSchedule(int* array, int n) {
	for(int i = 0; i < n; i++) {
		std::cout << array[i] << '\t';
	}
	std::cout << '\n';
}

int* randomSwap(int* array, int n) {
	// make a copy of the array
	int* temp;
	temp = new int[n];
	for (int i = 0; i < n; i++) {
		temp[i] = array[i];
	}
	// get two random indexes that will be swapped
	int index1 = random.nextInt(0, n - 1);
	int index2 = random.nextInt(0, n - 1);
	while (index1 ==  index2) {
		int index2 = random.nextInt(0, n - 1);
	}
	std::cout << "indexes " << index1 << " \t " << index2 << '\n';
	// perform swap
	temp[index1] = array[index2];
	temp[index2] = array[index1];

	printSchedule(temp, n);

}

solution simulatedAnnealing(int** array, int n) {
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
	int iterMax = 1;
	int	iter = 0;

	int* temp;
	temp = new int[n];
	while (iter < iterMax) {
		printSchedule(schedule, n);
		// get random solution from the neighbourhood
		randomSwap(schedule, n);
		printSchedule(schedule, n);

		iter++;
	}
}

#endif //SIMULATED_ANNEALING_SIMULATEDANNEALING_H
