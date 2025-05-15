#include "Registration.h"


// Parameterized ctor - 
Registration::Registration(const string& filename)
{
    // Open file for reading, In order to check if the file exists
    this->fileObj.open(filename, ios::binary | ios::in);
    // Case file does not exist
    if (!this->fileObj)
        // Create the file
        this->createFile(filename);
    else
        // Case file exists, Close file
        this->fileObj.close();

    // Open the file for reading and writing once file existance is ensured
    this->fileObj.open(filename, ios::binary | ios::in | ios::out);
    if (!fileObj)
        cout << "could not open file" << endl;
}


// dtor - Closes the binary file
Registration::~Registration()
{
    if (this->fileObj.is_open())
        this->fileObj.close();
}


bool Registration::createFile(const string& filename)
{
    this->fileObj.open(filename, ios::binary | ios::in | ios::out);
    if (!fileObj)
        return false;
    
    Student s;
    // Write 100 empty students to file
    this->fileObj.write((char*)&s, sizeof(s) * 100);
    // Close the file
    this->fileObj.close();
    // Signal success
    return true;
}


Student Registration::readStudent(const int& id)
{
    Student s;
    this->fileObj.seekg(id * (sizeof(s) - 1),ios::beg);
    this->fileObj.read((char*)&s, sizeof(s));
    this->fileObj.clear();

    return s;
}


void Registration::writeStudent(const Student& s)
{

}


void Registration::addStudent()
{

}


void Registration::deleteStudent()
{

}


void Registration::update()
{

}


bool Registration::checkRegistered()
{

}


void Registration::printStudent()
{

}


void Registration::printAll()
{

}
