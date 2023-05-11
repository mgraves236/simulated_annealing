#include <iostream>
#include "singleMachine.h"
#include "simulatedAnnealing.h"
#include "tests.h"

int main() {
//	int** jobs;
//	int const n = 4; // number of jobs
//	jobs = initialize_instance(89528, n);
//	printInstance(jobs, n);
//	solution sol = simulatedAnnealing(jobs, n, 0);
//	std::cout << "Best schedule:\t";
//	printSchedule(sol.schedule, n);
//	std::cout << "Cost:\t" << sol.tardinessSum;
	testNeighborhood();
	return 0;
}
