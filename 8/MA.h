#pragma once

#include "BA.h"

class MA : public BA
{
private: 
    bool research;

public:
    // Default ctor
    MA(int id = 0, string fn = "", string ln = "", int numCourses = 0);
    // Copy ctor
    MA(const MA&);
    // Move ctor
    MA(MA&&);
    // dtor
    ~MA() override;
    // Copy assignment
    MA& operator=(const MA&);
    // Move assignment
    MA& operator=(MA&&);

    // Research getter
    bool getResearch() const { return this->research; }
    // Research Setter
    void setResearch(bool r) { this->research = r; }

    // Method to compute whether the student is eligible for scholarship
    bool milga() const override final;
    // Method that returns the student type
    string studType() const override final { return "MA student"; }
    // Method to print student information and scholarship elegibility
    void print() const override final;
    // Method to get student information from the user
    void input() override final;
};