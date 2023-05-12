#include <iostream>
#include "singleMachine.h"
#include "simulatedAnnealing.h"
#include "tests.h"

/*
 * Optimal parameters
 * Neighborhood: Random Insert (1)
 * 				 Random Swap (2)
 * Iter Max: 250 000
 * For stagnation: 	depending on size of the instance and the instance itself
 * 					n < 12 : iterMax > 10 ;
 * 					n = 12 : 3
 * 					n > 12 : iterMax = 8
 * Initial temperature: depending on instance
 *
 *
 */
int main() {
	int** jobs;
	int const n = 17; // number of jobs
	jobs = initialize_instance(89528, n);
	printInstance(jobs, n);
	solution sol = simulatedAnnealing(jobs, n, 1, 250000, false, 0, 0.965);
	std::cout << "Best schedule:\t";
	printSchedule(sol.schedule, n);
	std::cout << "Cost:\t" << sol.tardinessSum << '\n';
	delete[] jobs;
	return 0;
}
