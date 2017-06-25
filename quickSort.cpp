#include "SinglyLList.h"
#include <string>

// quick sort
void SinglyLList::quickSort()
{
	ListNode *tail = nullptr;
	this->head = this->head != nullptr
		? quickSort(this->head, &tail) : nullptr;
}

static int record = 0;
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

//	int thisrecord = record++;
//	std::cout << "-------------------------------" << thisrecord << std::endl;
//	std::cout << "list after partition: "; print(leftlist); //degug
//	std::cout << "pivot: " << pivot->val << "  pivot_prev: " << 
//		(pivot_prev == nullptr ? "null" : std::to_string(pivot_prev->val)) << std::endl; //degug
	
	if (leftlist != pivot && rightlist != nullptr) { // if left list is not empty
		pivot_prev->next = nullptr;
//		std::cout << "rightlist: " << "case1(both ends not empty)" << "|"; print(rightlist); //debug
//		std::cout << "leftlist: "; print(leftlist); //debug
		rightlist = quickSort(rightlist, tail);
		leftlist = quickSort(leftlist, &pivot_prev);
//		std::cout << "concatnating..." << std::endl; //debug
		pivot_prev->next = pivot;
		pivot->next = rightlist;
//		std::cout << "after concatnate:" << "case1(both ends not epmty)" << "|"; print(leftlist); //debug
//		std::cout << "-------------------------------" << thisrecord << std::endl;
		return leftlist;
	} else if (rightlist == nullptr) {
//		std::cout << "rightlist: " << "case3(rightlist empty)" << "|"; print(rightlist); //debug
//		std::cout << "leftlist: "; print(leftlist); //debug
		pivot_prev->next = nullptr;
		leftlist = quickSort(leftlist, &pivot_prev);
		pivot_prev->next = pivot;
		*tail = pivot;
//		std::cout << "concatnating..." << std::endl; //debug
//		std::cout << "after concatnate:" << "case3(rightlist empty)" << "|"; print(leftlist); //debug
//		std::cout << "-------------------------------" << thisrecord << std::endl;
		return leftlist;
	} else { // left list is empty
//		std::cout << "rightlist: " << "case2(leftlist empty)" << "|"; print(rightlist); //debug
//		std::cout << "leftlist: "; print(leftlist); //debug
		pivot->next = nullptr;
		rightlist = quickSort(rightlist, tail);
//		std::cout << "concatnating..." << std::endl; //debug
		pivot->next = rightlist;
//		std::cout << "after concatnate:" << "case2(leftlist empty)" << "|"; print(leftlist); //debug
//		std::cout << "-------------------------------" << thisrecord << std::endl;
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
