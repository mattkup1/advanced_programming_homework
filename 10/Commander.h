/*
    Commander.h:
    Declaration of the Commander class, derived from PrivateSoldier.
    This class represents a commander in the military system, adding a combat flag
    to indicate whether the commander is in combat. It provides constructors,
    destructor, and overrides for medal eligibility, printing, and soldier type identification.
*/

#include "PrivateSoldier.h"

// Commander Class: Represents a commander with a combat flag
class Commander : public PrivateSoldier
{
private:
    bool combat; // Indicates if the commander is in combat

public:
    // Default ctor
    Commander();
    // Copy ctor
    Commander(const Commander&);
    // Move ctor
    Commander(Commander&&);
    // Virtual dtor
    ~Commander() {}

    bool isCombat() const { return this->combat; }

    // Method to compute whether the soldier should get a medal
    virtual bool medal() const override final;
    // Method to print soldier information
    virtual void print() const override final;
    // Method to get soldier type in string format
    virtual std::string soldierType() const override final { return "commander"; }
};