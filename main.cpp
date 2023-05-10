#include <iostream>
#include "singleMachine.h"
#include "simulatedAnnealing.h"

int main() {
	int** jobs;
	int const n = 3; // number of jobs
	jobs = initialize_instance(89528, n);
	printInstance(jobs, n);
	simulatedAnnealing(jobs, n);
	return 0;
}
