#pragma once

#include "List.h"

class RoundList : public List
{
public:
    // Default ctor
    RoundList();
    // Copy ctor
    RoundList(const RoundList&);
    // dtor
    ~RoundList();

    // Round List specific methods
    void addToEnd(const int&);    
    // Method to search for a value in the Round List by wrapping index 
    // Overrides the List class boolean search function 
    int search(const int&) const;   
    // Overriden List (parent) methods
    // Method to add argumented value to the head of the Round List
    void add(int);        
    // Method to remove the value at the head of the Round List                  
	void removeFirst();     
    // Method to clear all Round List values and free memory
    void clear();              
};