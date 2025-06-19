/*
    Soldier.cpp:
    Implementation file for the abstract Soldier class.
    This file provides the definitions for the Soldier class's constructors,
    copy/move constructors, and the virtual print method.
    The Soldier class serves as a base for all soldier types (PrivateSoldier, Commander, Officer)
    in the military system. It provides basic information such as ID, first name, last name,
    and number of operations, and enforces implementation of medal eligibility and soldier type
    identification in derived classes.
*/


#include "Soldier.h"

// Default constructor
// Prompts the user to enter the soldier's ID, first name, last name, and number of operations
Soldier::Soldier() 
{
    std::cout << "enter id, first name, last name and number of operations" << std::endl;
    std::cin >> this->id >> this->firstName >> this->lastName >> this->numOperations;
}

// Copy constructor
// Initializes a Soldier object as a copy of another Soldier object
Soldier::Soldier(const Soldier& src)
    : id(src.id), firstName(src.firstName),
    lastName(src.lastName), numOperations(src.numOperations)
{}

// Move constructor
// Initializes a Soldier object by transferring resources from another Soldier object
Soldier::Soldier(Soldier&& src)
    : id(src.id), firstName(src.firstName),
    lastName(src.lastName), numOperations(src.numOperations)
{}

// Virtual print method
// Prints the soldier's type and basic information
void Soldier::print() const
{
    std::cout << this->soldierType() << std::endl
            << "ID: " << this->id << std::endl
            << "first name: " << this->firstName << std::endl
            << "last name: " << this->lastName << std::endl
            << "num operations: " << this->numOperations << std::endl;
}