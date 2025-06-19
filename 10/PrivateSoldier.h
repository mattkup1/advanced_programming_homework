/*
    PrivateSoldier.h:
    Declaration of the PrivateSoldier class, derived from the abstract Soldier class.
    This class represents a private soldier in the military system, adding management
    of operation grades. Private soldiers are eligible for medals based on their
    performance in operations. The class provides constructors, destructor, and
    overrides for medal eligibility, printing, and soldier type identification.
*/

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