#include <iostream>
#include <fstream>
#include <unistd.h>

#include "SinglyLList.h"

void plot_allnlgn_random()
{
	const int total_iterations = 24;
	const int max_list_size = 100000;

	std::ofstream rmergeSortTime;
	std::ofstream imergeSortTime;
	std::ofstream nmergeSortTime;
	std::ofstream quickSortTime;
	rmergeSortTime.open("./plot/.plot_allnlgn_random_data_rms");
	imergeSortTime.open("./plot/.plot_allnlgn_random_data_ims");
	nmergeSortTime.open("./plot/.plot_allnlgn_random_data_nms");
	quickSortTime.open("./plot/.plot_allnlgn_random_data_qs");

	{
		SinglyLList list(50000);
		list.quickSort();
	}

	for (int list_size = 0; list_size <= max_list_size; list_size += 5000) {
		std::clock_t duration_rms = 0;
		std::clock_t duration_ims = 0;
		std::clock_t duration_nms = 0;
		std::clock_t duration_qs  = 0;

		for (int times = 1; times <= total_iterations; ++times) {
			SinglyLList randList(list_size);

			{
				SinglyLList list = randList;
				auto start_time = std::clock();
				list.rmergeSort();
				duration_rms += std::clock() - start_time;
			}

			{
				SinglyLList list = randList;
				auto start_time = std::clock();
				list.imergeSort();
				duration_ims += std::clock() - start_time;
			}

			{
				SinglyLList list = randList;
				auto start_time = std::clock();
				list.naturalmergeSort();
				duration_nms += std::clock() - start_time;
			}

			{
				SinglyLList list = randList;
				auto start_time = std::clock();
				list.quickSort();
				duration_qs += std::clock() - start_time;
			}
		}
			
		rmergeSortTime << list_size << "," << 1000. * duration_rms
			/ total_iterations / CLOCKS_PER_SEC;
		imergeSortTime << list_size << "," << 1000. * duration_ims
			/ total_iterations / CLOCKS_PER_SEC;
		nmergeSortTime << list_size << "," << 1000. * duration_nms
			/ total_iterations / CLOCKS_PER_SEC;
		quickSortTime  << list_size << "," << 1000. * duration_qs
			/ total_iterations / CLOCKS_PER_SEC;

		rmergeSortTime << std::endl;
		imergeSortTime << std::endl;
		nmergeSortTime << std::endl;
		quickSortTime  << std::endl;

		std::cout << "current : " << list_size << std::endl;
	}

	rmergeSortTime.close();
	imergeSortTime.close();
	nmergeSortTime.close();
	quickSortTime.close();
}
