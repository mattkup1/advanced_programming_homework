#include "Registration.h"
#include <filesystem>

Registration::Registration(const string& filename)
{
    this->fileObj->open(filename);
    if (!fileObj ->is_open())
        this->createFile(filename);

    Student s;
    // Write 100 empty students to the file
    for (int i = 0; i < 100; i ++)
    {
        writeStudent(s);
    }
    this->fileObj->close();
}

Registration::~Registration()
{
}

bool Registration::createFile(const string& filename)
{
    return false;
}

Student Registration::readStudent(const int& id)
{
    Student s;
    this->fileObj->clear();
    return s;
}

void Registration::writeStudent(const Student&)
{
}
