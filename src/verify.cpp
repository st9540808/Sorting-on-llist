#include <iostream>
#include "SinglyLList.h"

int main()
{
	SinglyLList list(10);
	list.print();
	list.quickSort();
	list.print();

	return 0;
}
