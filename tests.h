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
			solution sol = simulatedAnnealing(jobs, n, i, 1000, false, 10, 0.95);
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
		solution sol = simulatedAnnealing(jobs, n, 1, iter, false, 10, 0.95);
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
		solution sol = simulatedAnnealing(jobs, n, 1, 250000, false, 10, 0.95);
		file << sol.tardinessSum << '\t';
		sol = simulatedAnnealing(jobs, n, 1, 10, true, 10, 0.95);
		file << sol.tardinessSum << '\n';
	}
	file.close();
}

void testTemperature() {
	std::fstream file;
	file.open("temperature3.txt", std::ios::out);
	int **jobs;
	double maxTemp = 100;
	double	t = 1;
	int const n = 8; // number of jobs
	solution sol{};
	double sum = 0;
	while (t <= maxTemp) {
		std::cout << "t = \t" << t << '\n';
		file << t << '\t';
		for (int i = 1; i < 100; i++) {
			jobs = initialize_instance(89528 * i, n);
			sol = simulatedAnnealing(jobs, n, 1, 250000, false, t, 0.95);
			sum += sol.tardinessSum;
		}
		file << sum / 10 << '\n';
		t += 1;
	}
	file.close();
}

void testTemperatureVersion() {
	std::fstream file;
	file.open("temperatureVersion2.txt", std::ios::out);
	int **jobs;
	int maxSize = 85;
	solution sol{};
	for (int j = 80; j < maxSize + 1; j++) {
		std::cout << "n = \t" << j << '\n';
		int const n = j; // number of jobs
		file << n << '\t';
		double sumN = 0;
		double sum = 0;
		for (int i = 0; i < 10; i++) {
			jobs = initialize_instance(89528 * i, n);
			sol = simulatedAnnealing(jobs, n, 1, 250000, false, 7, 0.95);
			sum += sol.tardinessSum;
			sol = simulatedAnnealing(jobs, n, 1, 250000, false, 0, 0.95);
			sumN += sol.tardinessSum;

		}
		file << sum / 10 << '\t';

		file << sumN / 10 << '\n';
	}
	file.close();
}

void testAlpha() {
	std::fstream file;
	file.open("alpha.txt", std::ios::out);
	int **jobs;
	double maxAlpha = 0.99;
	double alpha = 0.95;
	int const n = 200; // number of jobs
	solution sol{};
	while (alpha <= maxAlpha) {
		double sum = 0;
		std::cout << "alpha = \t" << alpha << '\n';
		file << alpha << '\t';
		for (int i = 0; i < 5; i++) {
			std:: cout << i << ' ';
			jobs = initialize_instance(89528 * i, n);
			sol = simulatedAnnealing(jobs, n, 1, 250000, false, 0, alpha);
			sum += sol.tardinessSum;
		}
		file << sum / 10 << '\n';
		alpha += 0.005;
	}
	file.close();
}

void testCooling() {
	std::fstream file;
	file.open("cooling1.txt", std::ios::out);
	int **jobs;
	int maxSize = 40;
	solution sol{};
	for (int j = 3; j < maxSize + 1; j++) {
		std::cout << "n = \t" << j << '\n';
		int const n = j; // number of jobs
		file << n << '\t';
		double sum = 0;
		for (int i = 0; i < 10; i++) {
			jobs = initialize_instance(89528 * i, n);
			sol = simulatedAnnealing(jobs, n, 1, 250000, false, 0, 0.965);
			sum += sol.tardinessSum;
		}
		file << sum / 10 << '\n';
	}
	file.close();
}

void compare() {
	std::fstream file;
	file.open("compare.txt", std::ios::out);
	int **jobs;
	int maxSize = 100;
	for (int j = 3; j < maxSize + 1; j++) {
		std::cout << "n = \t" << j << '\n';
		int const n = j; // number of jobs
		file << n << '\t';
		jobs = initialize_instance(89528, n);
		solution sol = simulatedAnnealing(jobs, n, 0, 1000, false, 10, 0.99);
		solution solOpt = simulatedAnnealing(jobs, n, 1, 250000, false, 0, 0.965);
		file << sol.tardinessSum << '\t' << solOpt.tardinessSum << '\n';
	}
	file.close();
}

#endif //SIMULATED_ANNEALING_TESTS_H
