#include "Student.h"


Student::Student()
    : id(0) // Initialize id to 0
{
    // Initialize first and last name to ""
    this->firstName[0] = this-> lastName[0] = '\0';
    // Initialize all courses to false
    for (int i = 0; i < NUM_COURSES; ++i) 
    { 
        this->courses[i] = false; 
    }
}


Student::Student(const int& id, const char* fn, const char* ln)
    : id(id)
{
    // Case first name arg is null - initialize with ""
    if (fn == nullptr)
        this->firstName[0] = '\0';
    else
    // Case first name not null, Initialize first name with fn arg
        strncpy(this->firstName, fn, MAX_NAME_LEN);
    if (ln == nullptr)
        this->lastName[0] = '\0';
    else
        strncpy(this->lastName, ln, MAX_NAME_LEN);
    
    for (int i = 0; i < NUM_COURSES; i ++) 
    { 
        this->courses[i] = false; 
    }
}


// Operators
bool Student::operator[](const int& courseId) const
{
    if (courseId < 1 || courseId > 5)
    {
        cout << "ERROR" << endl;
        return false;
    }

    return this->courses[courseId - 1];
}


// Output operator '<<'
ostream& operator<<(ostream& os, const Student& s)
{
    os << s.id << " " << s.firstName << " " << s.lastName << " ";
    // Output only the course to which the student is signed up for
    for (int i = 0; i < NUM_COURSES; i++)
    {
        if (s.courses[i])
            os << i + 1 << " ";
    }
    return os;
}


// Input operator '>>'
istream& operator>>(istream& is, Student& s)
{
    char tmpFirstName[25];
    char tmpLastName[25];
    // Read id, first and last name
    is >> s.id >> tmpFirstName >> tmpLastName;
    // Read registered courses
    for (int i = 0; i < NUM_COURSES; ++i)
    {
        // For each ith course, Read 1 for registered and 0 for not registered
        is >> s.courses[i];
        // Case input is not 1 or 0, Set course state to 0 (not registered)
        if (s.courses[i] != 1 && s.courses[i] != 0)
            s.courses[i] = 0;
    }

    // Store corrected length
    strncpy(s.firstName, tmpFirstName, MAX_NAME_LEN);
    s.firstName[MAX_NAME_LEN] = '\0';
    strncpy(s.lastName, tmpLastName, MAX_NAME_LEN);
    s.lastName[MAX_NAME_LEN] = '\0';

    return is;
}