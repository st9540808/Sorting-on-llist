#include <iostream>
#include "SinglyLList.h"

int main()
{
	SinglyLList list(10);
	list.insertionSort();
	list.print();
	list.printPrem();

	return 0;
}
