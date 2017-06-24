#include "SinglyLList.h"

// insertion sort (stable)
SinglyLList::ListNode* SinglyLList::insertionSort() // stable sort
{
	if (head == nullptr or head->next == nullptr) return head;

	// nextPtr is always one step ahead of currentPtr
	ListNode *currentPtr = head, *nextPtr, **tempPtr;
	while (currentPtr->next != nullptr) {
		nextPtr = currentPtr->next;
		if (nextPtr->val < currentPtr->val) {
			for (tempPtr = &head
					; *tempPtr != nextPtr and (*tempPtr)->val <= nextPtr->val
					; tempPtr = &(*tempPtr)->next) ;
			currentPtr->next = nextPtr->next;
			nextPtr->next = *tempPtr;
			*tempPtr = nextPtr;
		} else {
			currentPtr = currentPtr->next;
		}
	}
	return head;
}

SinglyLList::ListNode* SinglyLList::insertionSort_old() // stable sort
{
	if (head == nullptr or head->next == nullptr) return head;

	// nextPtr is always one step ahead of currentPtr
	ListNode *currentPtr = head, *nextPtr, *tempPtr;
	while (currentPtr->next != nullptr) {
		nextPtr = currentPtr->next;

		if (nextPtr->val < currentPtr->val) {
			if (nextPtr->val < head->val) {
				// insert in the front of the list
				currentPtr->next = nextPtr->next;
				nextPtr->next = head;
				head = nextPtr;
			} else {
				for (tempPtr = head;
				        tempPtr->next != currentPtr and tempPtr->next->val <= nextPtr->val;
				        tempPtr = tempPtr->next) ;
				currentPtr->next = nextPtr->next;
				nextPtr->next = tempPtr->next;
				tempPtr->next = nextPtr;
			}
		} else {
			currentPtr = currentPtr->next;
		}
	}
	return head;
}
