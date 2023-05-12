//
// Created by Magda on 11.05.2023.
//

#ifndef SIMULATED_ANNEALING_TESTS_H
#define SIMULATED_ANNEALING_TESTS_H

#include <iostream>
#include <fstream>
#include <chrono>
#include "singleMachine.h"
#include "simulatedAnnealing.h"

void testNeighborhood() {
	std::fstream file;
	file.open("neighborhood.txt", std::ios::out);
	int **jobs;
	int maxSize = 100;
	for (int i = 0; i < 3; i++) {
		for (int j = 3; j < maxSize + 1; j++) {
			std::cout << "n = \t" << j << '\n';
			int const n = j; // number of jobs
			file << n << '\t';
			jobs = initialize_instance(89528, n);
			solution sol = simulatedAnnealing(jobs, n, i, 1000, false);
			file << sol.tardinessSum << '\n';
		}
	}
	file.close();
}

void testIteration() {
	std::fstream file;
	file.open("iteration.txt", std::ios::out);
	int const n = 20; // number of jobs
	int **jobs;
	int maxIter = 5242880 * 8;
	int iter = 10;
	while (iter <= maxIter) {
		std::cout << "iter = \t" << iter << '\n';
		file << iter << '\t';
		jobs = initialize_instance(89528, n);
		auto start = std::chrono::high_resolution_clock::now();
		solution sol = simulatedAnnealing(jobs, n, 1, iter, false);
		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
		file << sol.tardinessSum << "\t" << duration.count() << '\n';
		iter *= 2;
	}
	file.close();
}


void testIterationVersion() {
	std::fstream file;
	file.open("iterationVersion.txt", std::ios::out);
	int **jobs;
	int maxSize = 11;
	for (int j = 3; j < maxSize + 1; j++) {
		std::cout << "n = \t" << j << '\n';
		int const n = j; // number of jobs
		file << n << '\t';
		jobs = initialize_instance(89528, n);
		solution sol = simulatedAnnealing(jobs, n, 1, 250000, false);
		file << sol.tardinessSum << '\t';
		sol = simulatedAnnealing(jobs, n, 1, 10, true);
		file << sol.tardinessSum << '\n';
	}
	file.close();
}


#endif //SIMULATED_ANNEALING_TESTS_H
