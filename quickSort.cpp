#include "SinglyLList.h"
#include <string>

// quick sort
void SinglyLList::quickSort()
{
	ListNode *tail = nullptr;
	this->head = this->head != nullptr ? quickSort(this->head, &tail) : nullptr;
}

SinglyLList::ListNode* SinglyLList::quickSort(ListNode *head, ListNode **tail)
{
	if (head->next == nullptr) {
		*tail = head;
		return head;
	}
	
	// seperate two list
	ListNode *leftlist = nullptr, *pivot_prev = nullptr;
	ListNode *pivot = partition(head, &leftlist, &pivot_prev);
	ListNode *rightlist = pivot->next;

	if (leftlist != pivot && rightlist != nullptr) { // if left list is not empty
		pivot_prev->next = nullptr;
		rightlist = quickSort(rightlist, tail);
		leftlist = quickSort(leftlist, &pivot_prev);
		pivot_prev->next = pivot;
		pivot->next = rightlist;
		return leftlist;
	} else if (rightlist == nullptr) { // right list is empty
		pivot_prev->next = nullptr;
		leftlist = quickSort(leftlist, &pivot_prev);
		pivot_prev->next = pivot;
		*tail = pivot;
		return leftlist;
	} else { // left list is empty
		pivot->next = nullptr;
		rightlist = quickSort(rightlist, tail);
		pivot->next = rightlist;
		return pivot;
	}
}

// take first element as pivot
SinglyLList::ListNode* SinglyLList::partition(
		ListNode *list, ListNode **newHead, ListNode **pivot_prev)
{
	ListNode *list_lessThanOrEq     = nullptr;
	ListNode *list_lessThanOrEq_end = nullptr;
	ListNode *list_greaterThan      = nullptr;
	ListNode *list_greaterThan_end  = nullptr;

	ListNode *pivot = list; list = list->next;
	while (list != nullptr) {
		ListNode *currentNode = list;
		list = list->next;
		
		if (currentNode->val <= pivot->val) {
			currentNode->next = list_lessThanOrEq;
			list_lessThanOrEq = currentNode;
			if (list_lessThanOrEq_end == nullptr) {
				list_lessThanOrEq_end = currentNode;
			}
		} else {
			currentNode->next = list_greaterThan;
			list_greaterThan = currentNode;
			if (list_greaterThan_end == nullptr) {
				list_greaterThan_end = currentNode;
			}
		}
	}

	if (list_lessThanOrEq != nullptr) {
		*newHead = list_lessThanOrEq;
		list_lessThanOrEq_end->next = pivot;
	} else {
		*newHead = pivot;
	}
	pivot->next = list_greaterThan;
	if (list_greaterThan != nullptr) {
		list_greaterThan_end->next = nullptr;
	}
	*pivot_prev = list_lessThanOrEq_end;
	return pivot;
}
