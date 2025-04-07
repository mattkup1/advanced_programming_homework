#pragma once

#include <iostream>

using namespace std;


class RoundVector
{
private: 
    const int capacity;
    int* vec;
    int head;
    int tail;

public:
    // Constructor
    RoundVector(const int& capacity);
    // Copy Constructor
    RoundVector(const RoundVector& rv);
    // Move Constructor
    RoundVector(RoundVector&& src);
    // Destructor
    ~RoundVector();
    
    // Getters
    int getCapacity() const;
    int getHead() const;
    int getTail() const;

    // Required methods
    bool isEmpty() const;
    bool isFull() const;
    void clear();
    void addNext(int);
    int removeFirst();
    int firstValue() const;
    void print() const;
};
