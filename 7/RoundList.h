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
    int search(const int&) const; // Overrides the List class boolean search function  
    // Overriden List (parent) methods
    void add(int);                          
	void removeFirst();     
    void clear();              
};