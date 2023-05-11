//
// Created by Magda on 11.05.2023.
//

#ifndef SIMULATED_ANNEALING_TESTS_H
#define SIMULATED_ANNEALING_TESTS_H
#include <iostream>
#include <fstream>
#include "singleMachine.h"
#include "simulatedAnnealing.h"

void testNeighborhood() {
	std::fstream file;
	file.open("neighborhood.txt", std::ios::out);
	int** jobs;
	int maxSize = 100;
	for (int i = 0; i < 3; i++) {
		for (int j = 3; j < maxSize + 1; j++) {
			std::cout << "n = \t" << j << '\n';
			int const n = j; // number of jobs
			file << n << '\t';
			jobs = initialize_instance(89528, n);
			solution sol = simulatedAnnealing(jobs, n, i);
			file << sol.tardinessSum << '\n';
		}
	}
	file.close();
}

void testIteration() {
	std::fstream file;
	file.open("iteration.txt", std::ios::out);
	int** jobs;
	int maxSize = 100;
	for (int i = 0; i < 3; i++) {
		for (int j = 3; j < maxSize + 1; j++) {
			std::cout << "n = \t" << j << '\n';
			int const n = j; // number of jobs
			file << n << '\t';
			int neighborhood = 0;
			jobs = initialize_instance(89528, n);
			solution sol = simulatedAnnealing(jobs, n, neighborhood);
			file << sol.tardinessSum << '\n';
		}
	}
	file.close();
}


#endif //SIMULATED_ANNEALING_TESTS_H
