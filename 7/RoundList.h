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
    int search(int) const;  
    // Overriden List (parent) methods
    void add(int);              
    bool search(const int&) const;                
	void removeFirst();     
    void clear();              
};