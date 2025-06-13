#pragma once

#include "Soldier.h"


class Officer : public Soldier
{
private:
    // Sociometric score
    int socScore;

public:
    // Default ctor
    Officer();
    // Copy ctor
    Officer(const Officer& src);
    // Move ctor
    Officer(Officer&&);
    // Virtual dtor
    ~Officer() {}

    int getSocScore() const { return this->socScore; }

    // Abstract method to compute whether the soldier should get a medal
    virtual bool medal() const override final;
    // Abstract Method to print soldier information
    void print() const override final;
    // Abstract Method to get soldier type in string format
    std::string soldierType() const override final { return "officer"; }
};