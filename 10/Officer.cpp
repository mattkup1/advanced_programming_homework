/*
    Officer.cpp:
    Implementation file for the Officer class, derived from Soldier.
    This file provides the definitions for constructors, destructor, and methods
    that manage officer-specific functionality such as the sociometric score and
    medal eligibility. Officers can earn medals based on their number of operations
    and sociometric score.
*/

#include "Officer.h"


// Default constructor
// Initializes an Officer object and prompts user for sociometric score
Officer::Officer()
    : Soldier(), socScore(0)
{
    std::cout << "enter the sociometric score" << std::endl;
    std::cin >> this->socScore;
}


// Copy constructor
// Creates a deep copy of another Officer, including sociometric score
Officer::Officer(const Officer& src)
    : Soldier(src), socScore(src.socScore)
{}


// Move constructor
// Transfers ownership of data from source Officer, including sociometric score
Officer::Officer(Officer&& src)
    : Soldier(std::move(src)), socScore(src.socScore)
{
    // Reset the source's socScore to prevent accidental reuse
    src.socScore = 0;
}


// Medal eligibility check
// Returns true if officer participated in more than 2 operations and has a sociometric score >= 92
bool Officer::medal() const
{
    return this->numOperations > 2 && this->socScore >= 92;
}


// Print method
// Displays officer info, including sociometric score
void Officer::print() const
{
    // Print base class (Soldier) info
    this->Soldier::print();
    // Print sociometric score
    std::cout << "sociometric score: " << this->socScore << std::endl;
}