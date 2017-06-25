#include <iostream>
#include <fstream>
#include "SinglyLList.h"

void prob_insertionSortFaster()
{
	const int total_iterations = 100000;
	std::ofstream probabilityRms;
	std::ofstream probabilityIms;
	std::ofstream probabilityQs;
	probabilityRms.open("./plot/prob_insertionSortFaster_data_rms");
	probabilityIms.open("./plot/prob_insertionSortFaster_data_ims");
	probabilityQs.open("./plot/prob_insertionSortFaster_data_qs");

	for (int list_size = 1; list_size <= 100; ++list_size) {
		int timesFaster1 = 0;
		int timesFaster2 = 0;
		int timesFaster3 = 0;
		
		for (int times = 1; times <= total_iterations; ++times) {
			SinglyLList randList(list_size); // base list
			
			// to solve by insertion sort
			SinglyLList list1 = randList;
			auto start_time_1 = std::chrono::high_resolution_clock::now();
			list1.insertionSort();
			auto end_time_1 = std::chrono::high_resolution_clock::now();
			auto duration1  = std::chrono::duration_cast // insertion sort CPU Time
				<std::chrono::nanoseconds>(end_time_1 - start_time_1).count();


			// to solve by merge sort (recursive)
			SinglyLList list2 = randList;
			auto start_time_2 = std::chrono::high_resolution_clock::now();
			list2.rmergeSort();
			auto end_time_2 = std::chrono::high_resolution_clock::now();
			auto duration2  = std::chrono::duration_cast // merge sort CPU Time
				<std::chrono::nanoseconds>(end_time_2 - start_time_2).count();

			// to solve by merge sort (iterative)
			SinglyLList list3 = randList;
			auto start_time_3 = std::chrono::high_resolution_clock::now();
			list3.imergeSort();
			auto end_time_3 = std::chrono::high_resolution_clock::now();
			auto duration3  = std::chrono::duration_cast // iterative merge sort CPU Time
				<std::chrono::nanoseconds>(end_time_3 - start_time_3).count();
			
			// to solve by quick sort
			SinglyLList list4 = randList;
			auto start_time_4 = std::chrono::high_resolution_clock::now();
			list4.quickSort();
			auto end_time_4 = std::chrono::high_resolution_clock::now();
			auto duration4  = std::chrono::duration_cast // quick sort CPU Time
				<std::chrono::nanoseconds>(end_time_4 - start_time_4).count();
			

			if (static_cast<long>(duration1) < static_cast<long>(duration2)) {
				++timesFaster1;
			}
			if (static_cast<long>(duration1) < static_cast<long>(duration3)) {
				++timesFaster2;
			}
			if (static_cast<long>(duration1) < static_cast<long>(duration4)) {
				++timesFaster3;
			}
		}
		std::cout << "current : " << list_size << std::endl;

		probabilityRms << list_size << "," << static_cast<double>(timesFaster1)
			/ static_cast<double>(total_iterations) << std::endl;
		probabilityIms << list_size << "," << static_cast<double>(timesFaster2)
			/ static_cast<double>(total_iterations) << std::endl;
		probabilityQs << list_size << "," << static_cast<double>(timesFaster3)
			/ static_cast<double>(total_iterations) << std::endl;
	}

	probabilityRms.close();
	probabilityIms.close();
	probabilityQs.close();
}
