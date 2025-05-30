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

    // Methods
    void addToEnd(const int&);              
    int search(const int&) ;                
    bool search(const int& value) const;                
	void removeFirst();     
    void clear();                
};