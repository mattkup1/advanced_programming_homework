#include "PrivateSoldier.h"


// Default ctor
PrivateSoldier::PrivateSoldier()
    : Soldier(), opGrades(nullptr)
{
    if (this->numOperations > 0)
    {
        this->opGrades = new int[this->numOperations];
        std::cout << "enter " << this->numOperations << " grades" << std::endl;
        for (int i = 0; i < this->numOperations; ++i)
            std::cin >> this->opGrades[i];
    }
}


// Copy ctor
PrivateSoldier::PrivateSoldier(const PrivateSoldier& src)
    : Soldier(src), opGrades(nullptr)
{
    if (this->numOperations > 0)
    {
        this->opGrades = new int[this->numOperations];

        for (int i = 0; i < this->numOperations; ++i)
            this->opGrades[i] = src.opGrades[i];
    }
}


// Move ctor
PrivateSoldier::PrivateSoldier(PrivateSoldier&& src)
    : Soldier(src), opGrades(src.opGrades)
{
    src.opGrades = nullptr;
    src.numOperations = 0;
}


// Dtor
PrivateSoldier::~PrivateSoldier()
{
    delete [] this->opGrades;
    this->opGrades = nullptr;
}


// Method to compute whether the soldier should get a medal
// For Private: Participated in at least 10 operations and obtains an average grade of 95+
bool PrivateSoldier::medal() const
{
    if (this->numOperations < 10)
        return false;
    
    int sum = 0;
    for (int i = 0; i < numOperations; ++i)
        sum += this->opGrades[i];
    return sum / numOperations >= 95;
}


// Method to print soldier information
void PrivateSoldier::print() const
{
    Soldier::print();
    std::cout << "num operations: " << this->numOperations;

    if (this->numOperations > 0)
    {
        for (int i = 0; i < this->numOperations; ++i)
            std::cout << this->opGrades[i] << " ";
        std::cout << std::endl;
    }
}
