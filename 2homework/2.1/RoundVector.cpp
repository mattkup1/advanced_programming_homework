#include "RoundVector.h"

#include <iostream>

using namespace std;


// Constructor
RoundVector::RoundVector(const int& argCapacity) : capacity(argCapacity), tail(0), head(0)
{
    this->vec = new int[capacity + 1];

    cout << "in constructor" << endl;
}

// Copy Constructor
RoundVector::RoundVector(const RoundVector& src) : capacity(src.getCapacity())
{
    this->vec = new int[this->capacity + 1];
    this->head = this->tail = 0;
    
    for (int i = src.getHead();
        i != src.getTail();
        i = (i + 1) % (this->capacity + 1), this->tail = ((this->tail + 1) % (this->capacity + 1)))
    {
        this->vec[this->tail] = src.vec[i];
    }

    cout << "in copy constructor" << endl;
}


// Move Constructor
RoundVector::RoundVector(RoundVector&& src) 
    : capacity(src.getCapacity()), head(src.getHead()),
    tail(src.getTail()), vec(src.vec)
{
    src.vec = nullptr;
}


// Destructor
RoundVector::~RoundVector() 
{
    delete [] this->vec;
    cout << "in destructor" << endl;
}

// Getters
int RoundVector::getCapacity() const
{
    return this->capacity;
}


int RoundVector::getHead() const
{
    return this->head;
}


int RoundVector::getTail() const
{
    return this->tail;
}


    // Required methods
    bool RoundVector::isEmpty() const
    {
        return (this->head == this->tail);
    }


    bool RoundVector::isFull() const
    {
        return ((tail + 1) % (capacity + 1) == this->head);
    }


    void RoundVector::clear()
    {
        this->head = this->tail = 0;
    }


    void RoundVector::addNext(int n)
    {
        if (this->isFull())
        {
            cout << "Vector is full" << endl;
            return;
        }
        this->vec[this->tail] = n;
        
        this->tail = (this->tail + 1) % (this->capacity + 1);
    }


    int RoundVector::removeFirst()
    {
        if (this->isEmpty())
        {
            cout << "Vector is empty" << endl;
            return -1;
        }

        int removedValue = this->vec[this->head];

        this->head = (this->head + 1) % (this->capacity + 1);

        return removedValue;
    }


    int RoundVector::firstValue() const
    {
        if (this->isEmpty())
        {
            cout << "Vector is empty" << endl;
            return -1;
        }

        return this->vec[this->head];
    }


    void RoundVector::print() const
    {
        for (int i = this->head; i != this->tail; i = ((i + 1) % (this->capacity + 1)))
        {
            cout << this->vec[i] << " ";
        }
        cout << endl;
    }


