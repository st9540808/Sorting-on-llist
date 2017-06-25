#include <iostream>
#include "SinglyLList.h"

int main()
{
	for (int i = 0; i < 100; ++i) {
		SinglyLList list(i);
		list.quickSort();
		if (!list.isSorted()) {
			std::cout << "error in: " << std::endl;
			list.print();
		}
	}

	return 0;
}
