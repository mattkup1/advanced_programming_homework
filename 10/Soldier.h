# pragma once

#include <iostream>
#include <string>

// Abstract Class: Soldier
class Soldier
{
protected:
    int id;
    std::string firstName;
    std::string lastName;
    int numOperations;

public:
    // Default ctor
    Soldier();
    // Copy ctor
    Soldier(const Soldier& src);
    // Move ctor
    Soldier(Soldier&&);
    // Virtual dtor
    virtual ~Soldier() {}

    // Getters
    int getId() const { return this->id; }
    std::string getFirstName() const { return this->firstName; }
    std::string getLastName() const { return this->lastName; }
    int getNumOperations() const { return this->numOperations; }

    // Abstract method to compute whether the soldier should get a medal
    virtual bool medal() const = 0;
    // Abstract Method to print soldier information
    virtual void print() const;
    // Abstract Method to get soldier type in string format
    virtual std::string soldierType() const = 0;
};