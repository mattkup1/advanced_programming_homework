#include "Officer.h"


// Default ctor
Officer::Officer()
    : Soldier(), socScore(0)
{
    std::cout << "Enter the sociometric score:" << std::endl;
    std::cin >> this->socScore;
}


// Copy ctor
Officer::Officer(const Officer& src)
    : Soldier(src), socScore(src.socScore)
{}


// Move ctor
Officer::Officer(Officer&& src)
    : Soldier(std::move(src)), socScore(src.socScore)
{
    // Reset the source's socScore
    src.socScore = 0;
}


// Method to compute whether the soldier should get a medal
bool Officer::medal() const
{
    return this->numOperations >= 2 && this->socScore >= 92;
}


// Method to print soldier information
void Officer::print() const
{
    this->Soldier::print();
    std::cout << "sociometric Score: " << this->socScore << std::endl;
}