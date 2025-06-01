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


int RoundList::search(const int& index) const
{
    if (this->isEmpty())
        throw "List empty, Cannot search empty list";

    Link* ptr = this->head;
    for (unsigned i = 0; i < index; i++)
        ptr = ptr->next;
    return ptr->value;
}


void RoundList::add(int value)
{
    // Add new node to head
    this->head = new Link(value, this->head);

    // Case added node is the first node in the list - point next to self
    if (this->head->next == nullptr)
    {
        this->head->next = this->head;
        return;
    }

    // Point last node to new node
    Link* last = this->head->next;
    while (last->next != this->head->next)
        last = last->next;
    last->next = this->head;
}


void RoundList::removeFirst()
{
    // make sure there is a first element
	if (this->isEmpty())
		throw "List empty, no Elements to remove";

    // Case one node in the list
    if (this->head->next == this->head)
    {
        delete this->head;
        this->head = nullptr;
        return;
    }

	// save pointer to the staged node for removal
	Link* last = head;

    // Find last node
    while (last->next != this->head)
        last = last->next;

    // Store pointer to first node temporarily
    Link* temp = this->head;
    // Reassign head pointer to second node in the list
    this->head = this->head->next;
    // Set next pointer of last node in the list to the new head of the list
    last->next = this->head;
    // Free memory of deleted node
    delete temp;
}


void RoundList::clear()
{
    if (this->isEmpty())
        return;

    // Empty circular list and free memory for all nodes
    Link* ptr = this->head->next;
    // Traverse the list
    while (ptr != this->head)
    {
        Link* next = ptr->next;
        ptr->next = nullptr;
        delete ptr;
        ptr = next;
    }
    // Free first node
    this->head->next = nullptr;
    delete this->head;
    this->head = nullptr;
}