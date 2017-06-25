/**
 * Singly Linked list re-implementation
 * this will emphasize on advance operation on SinglyLList
 */
#ifndef SINGLYLLIST_RE_H
#define	SINGLYLLIST_RE_H

#include <iostream>
#include <algorithm>
#include <array>
#include <random>
#include <chrono>


class SinglyLList {
	struct ListNode {
		int val;
		int perm; // is used to check stable sorting
		ListNode *next;
		ListNode(int x) : val(x), next(nullptr) {};
		ListNode(int x, int y) : val(x), perm(y), next(nullptr) {};
	};

public:
	SinglyLList(int = 0, int = 0); // including range, default to generate a random linked list of size 10
	SinglyLList(const SinglyLList&); // copy constructor
	SinglyLList& operator=(SinglyLList); // copy assignment
	SinglyLList(SinglyLList&&) = default;
	SinglyLList& operator=(SinglyLList&&) = default;
	~SinglyLList();
	
	bool       isEmpty() const          { return head == nullptr; }
	uint32_t   getSize() const          { return size; }
	void       print() const;
	void       print(ListNode *) const;
	bool       isSorted() const;
	void       printPrem() const;
	void       insertAtFront(int);
	void       insertAtBack(int);

	// quick sort
	void quickSort();
	ListNode* quickSort(ListNode *, ListNode **);
	ListNode* partition(ListNode *, ListNode **, ListNode **);

	// merge sort and its variation
	void naturalmergeSort(); // natural mergesort
	void imergeSort(); // iterative mergesort, capable of sorting 2^31-1 nodes (arround 34.36 GB)
	void rmergeSort(); // recursive mergesort
	ListNode* rmergeSort(ListNode *head);
	ListNode* merge(ListNode *left, ListNode *right);
	ListNode* getMiddle(ListNode *head);
	 
	// insertion sort (stable)
	ListNode* insertionSort();
	ListNode* insertionSort_old();

private:
	ListNode *head;
	uint32_t size;
};

#endif
