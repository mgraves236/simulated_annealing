#include <iostream>
#include "singleMachine.h"
#include "simulatedAnnealing.h"

int main() {
	int** jobs;
	int const n = 10; // number of jobs
	jobs = initialize_instance(89528, n);
	printInstance(jobs, n);
	solution sol = simulatedAnnealing(jobs, n);
	std::cout << "Best schedule:\t";
	printSchedule(sol.schedule, n);
	std::cout << "Cost:\t" << sol.tardinessSum;
	return 0;
}
