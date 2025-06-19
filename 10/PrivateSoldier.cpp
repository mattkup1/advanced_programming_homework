/*
    PrivateSoldier.cpp:
    Implementation file for the PrivateSoldier class, derived from Soldier.
    This file provides definitions for constructors, destructor, and methods that manage
    private soldier-specific functionality such as operation grades and medal eligibility.
    Private soldiers can earn medals based on their participation in operations (minimum 10)
    and maintaining a high grade average (95+).
*/

#include "PrivateSoldier.h"

// Default constructor
// Initializes a private soldier and prompts for grades if operations exist
PrivateSoldier::PrivateSoldier()
    : Soldier(), opGrades(nullptr)
{
    // Allocate and populate grades array if soldier has operations
    if (this->numOperations > 0)
    {
        this->opGrades = new int[this->numOperations];
        std::cout << "enter " << this->numOperations << " grades" << std::endl;
        // Read grades for each operation from user input
        for (int i = 0; i < this->numOperations; ++i)
            std::cin >> this->opGrades[i];
    }
}

// Copy constructor
// Creates a deep copy of another private soldier, including grades array
PrivateSoldier::PrivateSoldier(const PrivateSoldier& src)
    : Soldier(src), opGrades(nullptr)
{
    // Deep copy of grades array if operations exist
    if (this->numOperations > 0)
    {
        this->opGrades = new int[this->numOperations];
        // Copy each grade from source object
        for (int i = 0; i < this->numOperations; ++i)
            this->opGrades[i] = src.opGrades[i];
    }
}

// Move constructor
// Transfers ownership of grades array from source object
PrivateSoldier::PrivateSoldier(PrivateSoldier&& src)
    : Soldier(src), opGrades(src.opGrades)
{
    // Clear source object's data to prevent double deletion
    src.opGrades = nullptr;
    src.numOperations = 0;
}

// Destructor
// Releases dynamically allocated grades array
PrivateSoldier::~PrivateSoldier()
{
    delete [] this->opGrades;
    this->opGrades = nullptr;
}

// Medal eligibility check
// Returns true if soldier participated in 10+ operations with 95+ average
bool PrivateSoldier::medal() const
{
    // Check minimum operations requirement
    if (this->numOperations < 10)
        return false;
    
    // Calculate average grade
    int sum = 0;
    for (int i = 0; i < numOperations; ++i)
        sum += this->opGrades[i];
    return sum / numOperations >= 95;
}

// Print method
// Displays soldier type, base info, and all operation grades
void PrivateSoldier::print() const
{
    // Print base class info (includes soldier type)
    Soldier::print();

    // Print grades if they exist
    if (this->numOperations > 0)
    {
        std::cout << "grades: ";
        for (int i = 0; i < this->numOperations; ++i)
            std::cout << this->opGrades[i] << " ";
        std::cout << std::endl;
    }
}
