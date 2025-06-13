#pragma once

#include <iostream>
#include "Soldier.h"

// Child Class: PrivateSoldier
class PrivateSoldier : public Soldier
{
protected:
    int* opGrades;

public:
    // Default ctor
    PrivateSoldier();
    // Copy ctor
    PrivateSoldier(const PrivateSoldier&);
    // Move ctor
    PrivateSoldier(PrivateSoldier&&);
    // Virtual dtor
    virtual ~PrivateSoldier();

    // Method to compute whether the soldier should get a medal
    virtual bool medal() const override;
    // Method to print soldier information
    virtual void print() const override;
    // Method to get soldier type in string format
    virtual std::string soldierType() const override { return "private"; }
};