#pragma once

#include <iostream>

using namespace std;


class RoundVector
{
private: 
    const int capacity;
    int* vec = nullptr;
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
    // Getters
    bool isEmpty() const;       // Returns whether caller has no values
    bool isFull() const;        // Returns whether caller is full
    int firstValue() const;     // Returns vector[head] value if not empty
    // Setters                
    void clear();               // Sets head and tail to 0
    void addNext(int);          // Adds an element to the vector if not full                    
    int removeFirst();          // Removes vector[head] index if not empty
    // Print method
    void print() const; 
};
