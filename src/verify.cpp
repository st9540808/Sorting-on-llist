#include <iostream>
#include "SinglyLList.h"

int main()
{
/*	for (int i = 0; i < 1000; ++i) {
		SinglyLList list(i);
		list.quickSort();
		if (!list.isSorted()) {
			std::cout << "error in: " << std::endl;
			list.print();
		}
	}*/
	SinglyLList list(15);
	list.print();
	list.partiallySort(100);
	list.print();

	return 0;
}
