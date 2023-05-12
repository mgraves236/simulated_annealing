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

RandomNumberGenerator random = RandomNumberGenerator(925486458);


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

double getInitialTemperature(int** array, int* schedule, int n) {
	double pIni = 0.65;
	int* temp;
	temp = new int[n];
	copyArray(temp, schedule, n);
	int min = INT_MAX;
	int max = 0;

	for (int i = 0; i < 1000; i++) {
		std::shuffle(temp, temp + n, std::mt19937(std::random_device()()));
		int sum = tardinessSum(array, temp, n);
		if (sum < min) min = sum;
		if (sum > max) max = sum;
	}
	return - (-min+max) / log(pIni);
}

int* randomSwap(int* array, int const n) {
	int* temp;
	temp = new int[n];
	copyArray(temp, array, n);

	// get two random indexes that will be swapped
	int index1 = random.nextInt(0, n - 1);
	int index2 = random.nextInt(0, n - 1);
	while (index2 ==  index1) {
		index2 = random.nextInt(0, n - 1);
	}

	// perform swap
	temp[index1] = array[index2];
	temp[index2] = array[index1];

	return temp;
}

int* randomInsert(int* array, int const n) {
	int* temp;
	temp = new int[n - 1];
	// get a random index
	int index = random.nextInt(0, n - 1);

	// delete element from array
	int size = 0;
	int i = 0;
	while (size < n - 1) {
		if (i == index) {
			i++;
			continue;
		}
		temp[size] = array[i];
		size++;
		i++;
	}

	// insert at randomized index
	int* temp2;
	temp2 = new int[n];
	int insert = random.nextInt(0, n - 2);

	size = 0;
	i = 0;
	while (size < n) {
		if (i == insert) {
			temp2[i] = array[index];
		} else {
			temp2[i] = temp[size];
			size++;
		}
		i++;
	}
	return temp2;
}

int* adjacentInterchange(int* array, int const n) {
	int* temp;
	temp = new int[n];
	copyArray(temp, array, n);
	// get a random index
	int index = random.nextInt(0, n - 1);
	// always perform swap forward
	if (index == n - 1) {
		temp[index] = array[0];
		temp[0] = array[index];
	} else {
		temp[index] = array[index + 1];
		temp[index + 1] = array[index];
	}

	return temp;
}

// acceptance function
double p(int* array, int* temp, int n, double t, int** matrix) {
	int old = tardinessSum(matrix, array, n);
	int prob = tardinessSum(matrix, array, n);

	double p = exp(-((double) prob - (double) old) / t);
	return p;
}
solution simulatedAnnealing(int** array, int const n, int neighborhood, int iterMax, bool stagnation, double t, double alpha) {
	// randomize first permutation
	int schedule[n];
	for (int i = 0; i < n; i++) {
		schedule[i] = i;
	}
	// initial solution is a random permutation
	std::shuffle(schedule, schedule + n, std::mt19937(std::random_device()()));
//	double T = getInitialTemperature(array, schedule, n);

	double T = t;
	if (T == 0) T = getInitialTemperature(array, schedule, n);

	int best = 	tardinessSum(array, schedule, n);
	int* bestSchedule;
	bestSchedule = new int[n];
	copyArray(bestSchedule, schedule, n);
//	std::cout << "best " << best << '\n';

	// stop condition
	int	iter = 0;
	double TMin = T / 100;

	int* temp;
	temp = new int[n];
	while (iter < iterMax) {
		// get random solution from the neighbourhood
		if (neighborhood == 0) temp = adjacentInterchange(schedule, n);
		if (neighborhood == 1) temp = randomInsert(schedule, n);
		if (neighborhood == 2) temp = randomSwap(schedule, n);
		int tSum = tardinessSum(array, temp, n);
		if (tSum < best) {
			copyArray(schedule, temp, n);
		} else if (p(schedule, temp, n, T, array) >= random.nextFloat(.0,1.0)) {
			copyArray(schedule, temp, n);
		}
		if (tSum < best) {
			best = tSum;
			copyArray(bestSchedule, schedule, n);
		} else if (tSum == best) {
			if (stagnation) iter++;
		}
		T = alpha * T;

		if (!stagnation) iter++;
	}
	solution sol{};
	sol.schedule = bestSchedule;
	sol.tardinessSum = best;
	return sol;
}

#endif //SIMULATED_ANNEALING_SIMULATEDANNEALING_H
