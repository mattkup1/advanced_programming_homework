#include "Registration.h"


// ctor
Registration::Registration(const string& filename)
{
    // Open file for reading, In order to check if the file exists
    this->fileObj.open(filename, ios::binary | ios::in);
    // Case file does not exist
    if (!this->fileObj)
        // Create the file
        this->createFile(filename);
    else
        // Case file exists and is therefor open for reading, Close file
        this->fileObj.close();

    // Open the file for reading and writing once file existance is ensured
    this->fileObj.open(filename, ios::binary | ios::in | ios::out);
    if (!this->fileObj)
        cout << "could not open file" << endl;
    this->fileObj.clear();

    // File is now open for reading and writing
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
    this->fileObj.open(filename, ios::binary | ios::out | ios::trunc);
    if (!this->fileObj)
        return false;
    
    Student s;
    // Write 100 empty students to file
    for (int i = 0; i < NUM_STUDENTS; ++i)
    {
        this->fileObj.write((char*)&s, sizeof(s));
    }

    // Close the file
    this->fileObj.close();
    this->fileObj.clear();
    // Signal success
    return true;
}


Student Registration::readStudent(const int& studentId)
{
    Student s;
    this->fileObj.seekg(studentIndex(studentId),ios::beg);
    this->fileObj.read((char*)&s, sizeof(s));
    this->fileObj.clear();

    return s;
}


void Registration::writeStudent(const Student& s)
{
    // Write the student at the ID'th index in the file
    this->fileObj.seekp((s.getId() - 1) * sizeof(Student), ios::beg);
    this->fileObj.write((char*)&s, sizeof(s));
    fileObj.clear();
    return;
}


void Registration::addStudent()
{
    // Read student info into a new student object
    Student s;
    cout << "enter student's details: " << endl;
    cin >> s;

    // Store student's id in a variable to avoid calling the getter
    int id = s.getId();

    // Case id out of range - Return
    if (id <= 0 || id > NUM_STUDENTS)
        return;

    // Case student already exists in the file
    if (findStudent(id))
    {
        cout << "student already exists" << endl;
        return;
    }

    // Case student does not exist in the file, Add to file
    writeStudent(s);

    return;
}


void Registration::deleteStudent()
{
    // Get student's ID
    cout << "enter id of student to delete " << endl;
    int studentId;
    cin >> ws;
    cin >> studentId;

    // Case student does not exist
    if (!findStudent(studentId))
    {
        cout << "student does not exist" << endl;
        return;
    }
    // Else - Set index to empty student
    // Create an empty student object via default Student ctor
    Student s;
    this->fileObj.seekp(studentIndex(studentId), ios::beg);
    // Write the empty student object to the file
    this->fileObj.write((char*)&s, sizeof(s));
    this->fileObj.clear();

    cout << studentId << " deleted" << endl;
    return;
}


void Registration::update()
{
    // Get student info
    int studentId;
    cout << "enter id of student to update: " << endl;
    cin >> ws;
    cin >> studentId;

    // Case student does not exist
    if (!findStudent(studentId))
    {
        cout << "student does not exist" << endl;
        return;
    }

    // Get course number to sign student up for
    int courseId;
    cout << "enter a course num to register for: " << endl;
    cin >> courseId;
    if (courseId > 0 && courseId < 6)
    {
        bool tmpTrue = true;
        this->fileObj.seekp(courseIndex(studentId, courseId), ios::beg);
        this->fileObj.write((char*)&tmpTrue, sizeof(bool));
        this->fileObj.clear();
    }
    return;
}


void Registration::checkRegistered()
{
    int studentId, courseId;
    // Get student and course ID
    cout << "enter student id and course number" << endl;
    cin >> studentId >> courseId;
    
    // Print registration state
    cout << "student " << studentId << " is "
            << ((findStudent(studentId) 
                && readStudent(studentId)[courseId]) 
                ? "" : "not ")
            << "registered for course " 
            << courseId << endl;

    return;
}


void Registration::printStudent()
{
    int studentId;
    cout << "enter student id number: " << endl;
    cin >> studentId;
    
    if (!findStudent(studentId))
    {
        cout << "student does not exist" << endl;
        return;
    }

    Student s;

    this->fileObj.seekg(studentIndex(studentId), ios::beg);
    this->fileObj.read((char*)&s, sizeof(s));
    this->fileObj.clear();

    cout << s << endl;

    return;
}


void Registration::printAll()
{
    this->fileObj.seekg(0, ios::beg);
    Student s;
    for (int i = 0; i < NUM_STUDENTS; ++i)
    {
        this->fileObj.read((char*)&s, sizeof(s));
        if (s.getId() != 0)
            cout << s << endl;
    }
    this->fileObj.clear();
}


// Helper functions
// Funtction to search for a student in the binary file by ID
// Returns the students id if found or -1 if not found
bool Registration::findStudent(const int& studentId)
{
    return studentId == readStudent(studentId).getId();
}


int Registration::studentIndex(int studentId) const
{
    return ((studentId - 1) * sizeof(Student));
}


int Registration::courseIndex(int studentId, int courseId) const
{
    return (studentIndex(studentId)                         // Navigate to the student with the given id
            + sizeof(int)                           
            + (2 * (MAX_NAME_LEN + 1) * sizeof(char))
            + (courseId - 1) * sizeof(bool));               // Navigate to the given course number
}
