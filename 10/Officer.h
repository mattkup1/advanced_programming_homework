/*
    Officer.h:
    Declaration of the Officer class, derived from the abstract Soldier class.
    This class represents an officer in the military system, adding a sociometric score
    to the basic soldier information. It provides constructors, destructor, and overrides
    for medal eligibility, printing, and soldier type identification.
*/

#pragma once

#include "Soldier.h"

// Child Class: Officer
class Officer : public Soldier
{
private:
    int socScore;   // Sociometric score

public:
    // Default ctor
    Officer();
    // Copy ctor
    Officer(const Officer& src);
    // Move ctor
    Officer(Officer&&);
    // Virtual dtor
    ~Officer() {}

    // Sociometric score getter
    int getSocScore() const { return this->socScore; }

    // Abstract method to compute whether the soldier should get a medal
    virtual bool medal() const override final;
    // Abstract Method to print soldier information
    void print() const override final;
    // Abstract Method to get soldier type in string format
    std::string soldierType() const override final { return "officer"; }
};