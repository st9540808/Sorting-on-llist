#include <iostream>
#include "SinglyLList.h"

int main()
{
	{ // init
		SinglyLList list(100000);
		list.rmergeSort();
	}

	std::clock_t start_time_new = 0;
	std::clock_t duration_new   = 0;
	std::clock_t start_time_old = 0;
	std::clock_t duration_old   = 0;

	const int total_iterations = 3000;
	const int list_size = 1400;

	for (int i = 0; i < total_iterations; ++i) {
		SinglyLList randlist(list_size);

		{
			SinglyLList list = randlist;

			start_time_new = std::clock();
			list.insertionSort();
			duration_new += std::clock() - start_time_new;
		}

		{
			SinglyLList list = randlist;

			start_time_old = std::clock();
			list.insertionSort_old();
			duration_old += std::clock() - start_time_old;
		}
	}

	// output
	std::cout << "time for sorting a llist of size 250" << std::endl;
	std::cout << "new insertion time: " <<
		1000. * duration_new / CLOCKS_PER_SEC / total_iterations << std::endl;
	std::cout << "old insertion time: " <<
		1000. * duration_old / CLOCKS_PER_SEC / total_iterations << std::endl;

	return 0;
}
