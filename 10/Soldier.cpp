#include "Soldier.h"

Soldier::Soldier() 
{
    std::cout << "enter id, first name, last name and number of operations" << std::endl;
    std::cin >> this->id >> this->firstName >> this->lastName >> this->numOperations;
}

Soldier::Soldier(const Soldier& src)
    : id(src.id), firstName(src.firstName),
    lastName(src.lastName), numOperations(src.numOperations)
{}

Soldier::Soldier(Soldier&& src)
    : id(src.id), firstName(src.firstName),
    lastName(src.lastName), numOperations(src.numOperations)
{}


void Soldier::print() const
{
    std::cout << this->soldierType()
            << "ID: " << this->id << std::endl
            << "first name: " << this->firstName << std::endl
            << "last name: " << this->lastName << std::endl
            << "num operations: " << this->numOperations << std::endl;
}

