#include "RoundVector.h"

#include <iostream>

using namespace std;

// Default constructor: initializes an empty RoundVector with given capacity
// Memory is allocated for (capacity + 1) elements due to circular buffer logic
RoundVector::RoundVector(const int& argCapacity) : capacity(argCapacity), tail(0), head(0)
{
    this->vec = new int[capacity + 1];

    cout << "in constructor" << endl;
}

// Copy constructor: creates a deep copy of another RoundVector
RoundVector::RoundVector(const RoundVector& src) : capacity(src.getCapacity())
{
    this->vec = new int[this->capacity + 1];
    this->head = this->tail = 0;
    
    // Copy elements using circular indexing and update tail accordingly
    for (int i = src.getHead();
        i != src.getTail();
        i = (i + 1) % (this->capacity + 1), this->tail = ((this->tail + 1) % (this->capacity + 1)))
    {
        this->vec[this->tail] = src.vec[i];
    }

    cout << "in copy constructor" << endl;
}

// Move constructor: transfers ownership of resources from another RoundVector
RoundVector::RoundVector(RoundVector&& src) 
    : capacity(src.getCapacity()), head(src.getHead()),
    tail(src.getTail()), vec(src.vec)
{
    src.vec = nullptr;
}

// Destructor: releases allocated memory
RoundVector::~RoundVector() 
{
    delete [] this->vec;
    cout << "in destructor" << endl;
}

// Returns the maximum capacity of the vector (not including extra buffer slot)
int RoundVector::getCapacity() const
{
    return this->capacity;
}

// Returns the index of the head (first element)
int RoundVector::getHead() const
{
    return this->head;
}

// Returns the index of the tail (last+1 position)
int RoundVector::getTail() const
{
    return this->tail;
}

// Checks if the vector is empty
bool RoundVector::isEmpty() const
{
    return (this->head == this->tail);
}

// Checks if the vector is full
bool RoundVector::isFull() const
{
    return ((tail + 1) % (capacity + 1) == this->head);
}

// Resets the vector to empty state
void RoundVector::clear()
{
    this->head = this->tail = 0;
}

// Adds an element at the tail if not full
void RoundVector::addNext(int n)
{
    if (this->isFull())
    {
        cout << "Vector is full" << endl;
        return;
    }
    this->vec[this->tail] = n;
    
    // Update tail using circular indexing
    this->tail = (this->tail + 1) % (this->capacity + 1);
}

// Removes and returns the first (head) element if not empty
int RoundVector::removeFirst()
{
    if (this->isEmpty())
    {
        cout << "Vector is empty" << endl;
        return -1;
    }

    int removedValue = this->vec[this->head];

    // Update head using circular indexing
    this->head = (this->head + 1) % (this->capacity + 1);

    return removedValue;
}

// Returns the first element without removing it
int RoundVector::firstValue() const
{
    if (this->isEmpty())
    {
        cout << "Vector is empty" << endl;
        return -1;
    }

    return this->vec[this->head];
}

// Prints all elements from head to tail in order
void RoundVector::print() const
{
    for (int i = this->head; i != this->tail; i = ((i + 1) % (this->capacity + 1)))
    {
        cout << this->vec[i] << " "; // Circular indexing to print elements
    }
    cout << endl;
}
