#include "RoundList.h"


// Default ctor - Uses the parent class ctor
RoundList::RoundList() : List::List() {}


// Copy ctor - Uses the parent class copy ctor
RoundList::RoundList(const RoundList& src) : List::List(src) {}


// dtor - Cannot use parent class dtor due to added Round List properties
RoundList::~RoundList() 
{
    // Delete all values from the round list and free allocated memory
    this->clear();
}


void RoundList::addToEnd(const int& val)
{
    // Handle empty Round List case
    if (this->isEmpty())
    {
        // Add new value to the head of the list
        // Use the add method
        this->add(val);
        return;
    }

    Link* last = this->head;
    // Find the last node in the Round List
    while (last->next != this->head)
    {
        last = last->next;
    }
    // Add a node with the argumented value at the end of the Round List
    // And set it's next pointer to the head of the list to maintain Round List attributes
    last->next = new Link(val, this->head);
}


int RoundList::search(const int& index) const
{
    // Handle empty list case
    if (this->isEmpty())
        throw "List empty, Cannot search empty list";

    // Find the value at the argumented index
    // Wrap to head if index is greater than the number of values in the Round List
    Link* ptr = this->head;
    for (unsigned i = 0; i < index; i++)
        ptr = ptr->next;
    // Return the value at argumented index
    return ptr->value;
}


void RoundList::add(int value)
{
    // Add new node to head
    this->head = new Link(value, this->head);

    // Handle case added node is the first node in the list
    if (this->head->next == nullptr)
    {
        // Set new node's next pointer to self 
        // Affectively pointing the last node in the list to the head of the list
        this->head->next = this->head;
        return;
    }

    Link* last = this->head->next;
    // Find last node in the list
    while (last->next != this->head->next)
        last = last->next;
    // Set the next pointer of last node in the Round List
    // to the new node to maintain Round List attributes
    last->next = this->head;
}


void RoundList::removeFirst()
{
    // make sure there is a first element
	if (this->isEmpty())
		throw "List empty, no Elements to remove";

    // Handle case Round List contains only one node
    // Deleting the first node will effectively leave the list empty
    // in which case, Head pointer needs to be set to NULL
    // For compatibility with the isEmpty function
    if (this->head->next == this->head)
    {
        // Reset first node's next pointer
        this->head->next = nullptr;
        // Free allocated memory
        delete this->head;
        // Set head pointer to NULL
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
    // Handle empty list case
    if (this->isEmpty())
        return;

    // Empty circular list and free memory for all nodes
    Link* ptr = this->head->next;
    // Traverse the list from the second node 
    // End loop upon wrapping to the head of the list
    while (ptr != this->head)
    {
        // Store the address of the next node 
        Link* next = ptr->next;
        // Reset current node's next pointer
        ptr->next = nullptr;
        // Delete current node's allocated memory
        delete ptr;
        // Repeat for next node in the Round List
        ptr = next;
    }
    // Reset first node's next pointer
    this->head->next = nullptr;
    // Free first node's allocated memory
    delete this->head;
    // Set head pointer to NULL to signal that the list is empty
    // (isEmpty function requirements)
    this->head = nullptr;
}