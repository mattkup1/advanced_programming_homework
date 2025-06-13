#include "PrivateSoldier.h"

class Commander : public PrivateSoldier
{
private:
    bool combat;

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