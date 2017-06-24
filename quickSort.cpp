#include "SinglyLList.h"

// quick sort
void SinglyLList::quickSort() {
	ListNode *tail = nullptr;
	this->head = quickSort(this->head, &tail);
}

SinglyLList::ListNode* SinglyLList::quickSort(ListNode *head, ListNode **tail) {
	if (head == nullptr || head->next == nullptr) return head;
	ListNode *pivot = partition(head, &head);
	if (pivot != head) { // seperate into two list
		ListNode *tempPtr = pivot;
		pivot = pivot->next; tempPtr->next = nullptr;
		
		ListNode *left_tail = nullptr;
		ListNode *left  = quickSort(head, &left_tail);
		ListNode *right_tail = nullptr;
		ListNode *right = quickSort(pivot, &right_tail);
		left_tail->next = right;
		return left;
	}
}

SinglyLList::ListNode* SinglyLList::partition(ListNode *list, ListNode **newHead) {
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
	return pivot;
}
