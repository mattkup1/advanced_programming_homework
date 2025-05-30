#include "RoundList.h"


// Default ctor
RoundList::RoundList() : List::List() {}


// Copy ctor
RoundList::RoundList(const RoundList& src) : List::List(src) {}


// dtor
RoundList::~RoundList() 
{
    this->clear();
}


void RoundList::addToEnd(const int& val)
{
    if (this->isEmpty())
    {
        this->head = new Link(val, nullptr);
        this->head->next = this->head;
        return;
    }

    Link* ptr = this->head;
    while (ptr->next != this->head)
    {
        ptr = ptr->next;
    }
    ptr->next = new Link(val, this->head);
}


int RoundList::search(const int& index)
{
    if (this->isEmpty())
        throw "List empty, Cannot search empty list";

    Link* ptr = this->head;
    for (unsigned i = 0; i < index; i++)
        ptr = ptr->next;
    return ptr->value;
}


bool RoundList::search(const int& value) const
{
    if (this->isEmpty())
        throw "List empty, Cannot search empty list";
    Link* ptr = this->head;
    while (ptr->next != this->head)
        if (ptr->value == value)
            return true;
    // Case not found in iterations
    // Check last link and return true if found
    // And false if not found
    return ptr->value == value;
}


void RoundList::removeFirst()
{
    // make sure there is a first element
	if (this->isEmpty())
		throw "List empty, no Elements to remove";
	// save pointer to the removed node
	Link* ptr = head;
    while ((ptr = ptr->next) != this->head)
	// Reassign the first node
	this->head = this->head->next;
    // Delete previous first node
	delete ptr->next;
    // Point last node at new first node
	ptr->next = head;
}


void RoundList::clear()
{
	// empty all elements from the List
    Link* headPtr = this->head;
    Link* ptr = this->head;
    Link* next;

	while (next != headPtr)
	{
		// delete the element pointed to by p
		next = ptr->next;
		ptr->next = nullptr;
		delete ptr;
        ptr = next;
	}
}