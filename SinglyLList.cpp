#include "SinglyLList.h"

// methods that are less important
SinglyLList::SinglyLList(int inputSize, int range)
: head(nullptr)
, size(inputSize)
{
	if (range == 0) range = inputSize;
	// random generate linked list
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> gen(0, range);

	if (this->size != 0) {
		ListNode *newNode = new ListNode(gen(generator), this->size);
		this->head = newNode;
	}

	for (uint32_t i = 1; i < size; ++i) {
		ListNode *newNode = new ListNode(gen(generator), this->size - i);
		newNode->next = this->head;
		this->head = newNode;
	}
}

SinglyLList::SinglyLList(const SinglyLList& rhs)
: head(nullptr)
, size(rhs.size)
{
	if (this != &rhs) {
		ListNode *const *rhsPtr = &rhs.head;
		ListNode **currentPtr   = &this->head;
		
		while (*rhsPtr != nullptr) {
			ListNode *newNode
				= new ListNode((*rhsPtr)->val, (*rhsPtr)->perm);
			*currentPtr = newNode;
			rhsPtr = &(*rhsPtr)->next;
			currentPtr = &(*currentPtr)->next;
		}
	}
}

SinglyLList& SinglyLList::operator=(SinglyLList rhs_copy)
{
	std::swap(this->head, rhs_copy.head);
	std::swap(this->size, rhs_copy.size);
	return *this;
}

SinglyLList::~SinglyLList()
{
	ListNode *currentPtr = this->head, *tempPtr;
	while (currentPtr != nullptr) {
		tempPtr = currentPtr;
		currentPtr = currentPtr->next;
		delete tempPtr;
	}
}

void SinglyLList::insertAtFront(int val)
{
	ListNode *newNode = new ListNode(val);
	ListNode *list = this->head;
	newNode->next = list;
	this->head = newNode;
}

void SinglyLList::insertAtBack(int val)
{
	ListNode *newNode = new ListNode(val);
	ListNode **currentPtr = &this->head;
	while (*currentPtr != nullptr) {
		currentPtr = &(*currentPtr)->next;
	}
	newNode->next = *currentPtr;
	*currentPtr = newNode;
}

void SinglyLList::print() const
{
	print(this->head);
}

void SinglyLList::print(ListNode *head) const
{
	ListNode *currentPtr = head;

	while (currentPtr != nullptr) {
		std::cout << currentPtr->val;
		std::cout << " -> ";
		currentPtr = currentPtr->next;
	}
	std::cout << "null\n";
}

bool SinglyLList::isSorted() const
{
	if (this->head == nullptr)
		return true;
	ListNode *currentPtr = this->head;
	while (currentPtr->next != nullptr) {
		if (currentPtr->next->val < currentPtr->val)
			return false;
		currentPtr = currentPtr->next;
	}
	return true;
}

void SinglyLList::printPrem() const
{
	ListNode *currentPtr = this->head;

	while (currentPtr != nullptr) {
		std::cout << currentPtr->perm;
		std::cout << " -> ";
		currentPtr = currentPtr->next;
	}
	std::cout << "null\n";
}
