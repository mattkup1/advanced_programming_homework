#include "Commander.h"


// Default ctor
Commander::Commander()
    : PrivateSoldier(), combat(false)
{
    std::cout << "enter 1 if the soldier is combat and 0 if not" << std::endl;
    std::cin >> this->combat;
}


// Copy ctor
Commander::Commander(const Commander& src)
    : PrivateSoldier(src), combat(src.combat)
{

}


// Move ctor
Commander::Commander(Commander&& src)
    : PrivateSoldier(std::move(src)), combat(src.combat)
{}

// Method to compute whether the soldier should get a medal
bool Commander::medal() const
{
    if (this->numOperations < 7 || !this->combat)
        return false;

    int sum = 0;

    for (int i = 0; i < this->numOperations; ++i)
        sum += this->opGrades[i];
    return sum / this->numOperations >= 90;
}


// Method to print soldier information
void Commander::print() const
{
    this->PrivateSoldier::print();
    std::cout << "combat: " << (this->combat ? "yes" : "no") << std::endl;
}