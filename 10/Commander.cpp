/*
    Commander.cpp:
    Implementation file for the Commander class, derived from PrivateSoldier.
    This file provides the definitions for constructors, destructor, and methods
    that manage commander-specific functionality such as the combat flag and
    medal eligibility. Commanders can earn medals based on their participation
    in operations, combat status, and maintaining a high grade average.
*/

#include "Commander.h"


// Default constructor
// Initializes a Commander object and prompts user for combat status
Commander::Commander()
    : PrivateSoldier(), combat(false)
{
    std::cout << "enter 1 if the soldier is combat and 0 if not" << std::endl;
    std::cin >> this->combat;
}


// Copy constructor
// Creates a deep copy of another Commander, including combat flag
Commander::Commander(const Commander& src)
    : PrivateSoldier(src), combat(src.combat)
{
    // No additional logic needed; combat flag copied
}


// Move constructor
// Transfers ownership of data from source Commander, including combat flag
Commander::Commander(Commander&& src)
    : PrivateSoldier(std::move(src)), combat(src.combat)
{
    // No additional logic needed; combat flag moved
}


// Medal eligibility check
// Returns true if commander participated in 7+ operations, is in combat, and has 90+ average
bool Commander::medal() const
{
    // Check minimum operations and combat status
    if (this->numOperations < 7 || !this->combat)
        return false;

    // Calculate average grade
    int sum = 0;
    for (int i = 0; i < this->numOperations; ++i)
        sum += this->opGrades[i];
    return sum / this->numOperations >= 90;
}


// Print method
// Displays commander info, including combat status
void Commander::print() const
{
    // Print base class (PrivateSoldier) info
    this->PrivateSoldier::print();
    // Print combat status
    std::cout << "combat: " << (this->combat ? "yes" : "no") << std::endl;
}