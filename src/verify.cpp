#include <iostream>
#include "SinglyLList.h"

int main()
{
	SinglyLList list;
//	list.insertAtFront(2);
	list.insertAtBack(2);
	list.insertAtBack(1);
	list.insertAtBack(3);
	list.insertAtBack(4);
	list.insertAtBack(5);
	list.quickSort();
	list.print();
//	list.printPrem();

	return 0;
}
