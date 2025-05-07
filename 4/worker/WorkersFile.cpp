#include "WorkersFile.h"


// ctor
WorkersFile::WorkersFile(const string& s)
{
    // Initialize file name
    fileName = s;
    // Clear file content
    openFileForWriting();
    closeFile();
}


// Function to open a file for writing
// Returns true if file opened successfully and false if not opened
bool WorkersFile::openFileForWriting() 
{
    // Open the file using iofile file stream
    iofile.open(fileName, ios::out);
    // Case file not opened
    if (!iofile.is_open())
    {
        cout << "ERROR" << endl;
        return false;
    }
    // Case file opened successfully
    return true;
}


// Function to open a file for reading
// Returns true if file opened successfully and false if not opened
bool WorkersFile::openFileForReading()
{
    // Open the file using iofile file stream
    iofile.open(fileName, ios::in);
    // Case file not opened
    if (!iofile.is_open())
    {
        cout << "ERROR" << endl;
        return false;
    }
    // Case file opened successfully
    return true;
}


// Close open file
void WorkersFile::closeFile()
{
    if(iofile.is_open())
        iofile.close();
}


// Operators
// Search Worker in file by id
// Return matched Worker object if found
// Else, Return empty Worker object
Worker WorkersFile::operator[](const int& id)
{
    if (this->openFileForReading())
    {
        // Create worker to read information
        // And return if match is found
        Worker w;
        // Iterate over all workers in the file
        while (this->iofile >> w)
        {
            // Case id match is found in the file
            // Close the file and return worker object with matching id
            if (w == id)
            {
                this->closeFile();
                return w;
            }
        }
        // Case no match found in loop, Close file
        this->closeFile();
    }
    // Case no match in file or file failed to open
    // Create and return an empty worker object
    Worker w;
    return w;
}


// Get worker by name
Worker WorkersFile::operator[](const string& name)
{
    if (this->openFileForReading())
    {
        // Create worker to read information
        // And return if match is found
        Worker w;
        while (this->iofile >> w)
        {
            // Case name match is found in the file
            // Close the file and return worker object with matching name
            if (w == name)
            {
                this->closeFile();
                return w;
            }
        }
        // Case no match found in loop, Close file
        this->closeFile(); 
    }
    
    // Case no match found or file failed to open
    // Create and return an empty Worker object
    Worker w;
    return w;
}


WorkersFile& WorkersFile::operator+=(const float & raise)
{
    // Get number of workers in the file
    int numWorkers = this->getNumWorkers();
    // Create a temporary array to store the workers information from the file
    Worker* tmp = new Worker[numWorkers];

    // Copy file content to helper array
    if (openFileForReading())
    {
        // Create a new file to write updated workers information to
        ofstream newFile("new_file.txt", ios::out);
        if (!newFile.is_open())
        {
            cout << "ERROR" << endl;
            closeFile();
            return *this;
        }

        // Create a worker object to read and update and rewrite worker information
        Worker w;
        // Read worker information from current file
        while (iofile >> w)
        {
            // Update salary using the Worker '+=' operator
            w += raise;
            // Write updated worker information to the new
            newFile << w;
        }
        // Close both files
        closeFile();
        newFile.close();

        // Replace the original file with the new file in file directory
        // Delete the original file
        remove(fileName.c_str());
        // Rename the new file to the original file name
        rename("new_file.txt", fileName.c_str());
    }
    // Case file failed to open
    else
    {
        cout << "ERROR" << endl;
    }

    return *this;
}

// Friend functions
// Input workers information to file
istream& operator>>(istream& is, WorkersFile& f)
{
    if (f.openFileForWriting())
    {
        Worker w;

        while (true)
        {
            is >> w;

            // Stop if worker's ID is 0
            if (w == 0)
                break;

            // Write worker information to the file
            f.iofile << w;
        }
        // Close the file after writing
        f.closeFile(); 
    }
    // Return the input stream
    return is;
}


// Print file to terminal
ostream& operator<<(ostream& os, WorkersFile& f)
{
    if (f.openFileForReading())
    {
        Worker w;
        // Read Worker objects from file
        while(f.iofile >> w)
        {
            // Write Worker object to output stream
            os << w << endl;
        }
        // Close the file after Reading
        f.closeFile();
    }
    // Return the output stream
    return os;
}

