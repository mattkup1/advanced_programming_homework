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
    if (!this->fileObj)
        cout << "could not open file" << endl;
    this->fileObj.clear();
}


// dtor - Closes the binary file
Registration::~Registration()
{
    if (this->fileObj.is_open())
        this->fileObj.close();
    this->fileObj.clear();
}


bool Registration::createFile(const string& filename)
{
    this->fileObj.open(filename, ios::binary | ios::in | ios::out);
    if (!this->fileObj)
        return false;
    
    Student s;
    // Write 100 empty students to file
    this->fileObj.write((char*)&s, sizeof(s) * 100);
    // Close the file
    this->fileObj.close();
    this->fileObj.clear();
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
    // Write the student at the ID'th index in the file
    this->fileObj.write((char*)&s + (s.getId() * sizeof(s)) - 1, sizeof(s));
    return;
}


void Registration::addStudent()
{
    Student s;
    cout << "enter student's details: " << endl;
    cin >> s;

    bool exists;
    // Check if student exists in file
    fileObj.seekg(s.getId() - 1, ios::beg);
    int tmp_id;
    // Read only the ID from the binary file
    fileObj.read((char*)&tmp_id, sizeof(int));
    if (tmp_id == s.getId())
    {
        // Case already exists - Print and exit
        cout << "student already exists" << endl;
        return;
    }

    fileObj.clear();

    // Case student does not exist in the file, Add to file
    writeStudent(s);

    return;
}


void Registration::deleteStudent()
{
    // Get student's ID
    cout << "enter id of student to delete: " << endl;
    int tmpId;
    cin >> tmpId;

    // Case student does not exist
    if (!findStudent(tmpId))
    {
        cout << "student does not exist" << endl;
        return;
    }
    // Else - Set index to empty student
    // Decrement ID to match file index
    --tmpId;
    Student s;
    this->fileObj.seekp(sizeof(s) * tmpId);
    this->fileObj.write((char*)&s, sizeof(s));
    this->fileObj.clear();

    cout << "deleted" << endl;
    return;
}


void Registration::update()
{
    // Get student info

    // Case student does not exist
    
    // Update student fields
}


bool Registration::checkRegistered()
{
    // Get info

    // Check and update
}


void Registration::printStudent()
{

}


void Registration::printAll()
{

}


// Helper functions
// Funtction to search for a student in the binary file by ID
// Returns the students id if found or -1 if not found
bool Registration::findStudent(const int& id)
{
    this->fileObj.seekg(sizeof(Student) * (id - 1), ios::beg);
    int tmp;
    this->fileObj.read((char*)&tmp, sizeof(tmp));
    fileObj.clear();
    return tmp == 0 ? false : true;
}
