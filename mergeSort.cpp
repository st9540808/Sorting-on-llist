#include "SinglyLList.h"

// natural mergesort
void SinglyLList::naturalmergeSort() {
	std::array<ListNode *, 31> paritialLists = {nullptr}; // lists of 2^i runs
	auto const beginIter = paritialLists.begin();
	auto const endIter = paritialLists.end();
	ListNode *remainingList = this->head;
	
	while (remainingList != nullptr) {
		auto *runHead = remainingList;
		auto *runTail = remainingList;
		while (runTail->next != nullptr and runTail->val <= runTail->next->val)
			runTail = runTail->next;
		remainingList = runTail->next;
		runTail->next = nullptr;

		if (paritialLists.front() == nullptr) {
			paritialLists.front() = runHead;
		} else {
			auto iter = beginIter;
			for (; *iter != nullptr; ++iter) {
				runHead = merge(*iter, runHead);
				*iter = nullptr;
			}
			*iter = runHead;
		}
	}
	
	for (auto iter = beginIter + 1; iter != endIter; ++iter) {
		*iter = merge(*iter, *(iter - 1));
	}
	this->head = paritialLists.back();
}

// iterative mergesort, it's capable of sorting 2^31-1 nodes (arround 34.36 GB)
void SinglyLList::imergeSort() {
	std::array<ListNode *, 31> paritialLists = {nullptr}; // lists of 2^i nodes
	auto const beginIter = paritialLists.begin();
	auto const endIter = paritialLists.end();
	ListNode *remainingList = this->head;
	
	while (remainingList != nullptr) {
		auto *result = remainingList;
		remainingList = remainingList->next;
		result->next = nullptr;
		
		if (paritialLists.front() == nullptr) {
			paritialLists.front() = result;
		} else {
			auto iter = beginIter;
			for (; *iter != nullptr; ++iter) {
				result = merge(*iter, result);
				*iter = nullptr;
			}
			*iter = result;
		}
	}
	
	for (auto iter = beginIter + 1; iter != endIter; ++iter) {
		*iter = merge(*iter, *(iter - 1));
	}
	this->head = paritialLists.back();
}

// recursive mergesort
void SinglyLList::rmergeSort() {
	this->head = (this->head == nullptr) ? nullptr : rmergeSort(this->head);
}

SinglyLList::ListNode* SinglyLList::rmergeSort(ListNode *head) {
	if (head->next == nullptr) return head;
	ListNode *mid = getMiddle(head);
	ListNode *halfList = mid->next;
	mid->next = nullptr;
	return merge(rmergeSort(head), rmergeSort(halfList));
}

SinglyLList::ListNode* SinglyLList::merge(ListNode *left, ListNode *right) {
	if (left == nullptr) return right;
	else if (right == nullptr) return left;
	
	static ListNode dummy(0);
	ListNode* currentPtr = &dummy;
	for (; left != nullptr and right != nullptr; currentPtr = currentPtr->next) {
		if (left->val <= right->val) {
			currentPtr->next = left;
			left = left->next;
		} else {
			currentPtr->next = right;
			right = right->next;
		}
	}

	currentPtr->next = (right == nullptr) ? left : right;
	return dummy.next;
}

SinglyLList::ListNode* SinglyLList::getMiddle(ListNode *head) {
	ListNode *slowPtr = head, *fastPtr = head;
	while (fastPtr->next != nullptr
	        and fastPtr->next->next != nullptr) {
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
	}
	return slowPtr;
}
