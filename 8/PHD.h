#pragma once

#include "Student.h"


class PHD : public Student
{
private:
    int weeklyResearchHrs;

public:
    // Default ctor
    PHD(int id = 0, string fn = "", string ln = "", int numCourses = 0, int hrs = 0);
    // Copy ctor
    PHD(const PHD&);
    // Move ctor
    PHD(PHD&&);
    // Copy assignment
    PHD& operator=(const PHD&);
    // Move assignment
    PHD& operator=(PHD&&);

    // Weekly Research Hours Getter
    int getWeeklyResearchHrs() const { return this->weeklyResearchHrs; }
    // Weekly Research Hours Setter
    void setWeeklyResearchHrs(int h) { this->weeklyResearchHrs = h; }

    // Method to compute whether the student is eligible for scholarship
    bool milga() const override final;
    // Method that returns the student type
    string studType() const override final { return "PHD"; }
    // Method to print student information and scholarship elegibility
    void print() const override final;
    // Method to get student information from the user
    void input() override final;
};