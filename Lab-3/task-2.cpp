/*Name: Muhammad Saad
  CMS: 548277
  Class: BSCS-15-D*/
  
#include <iostream>
#include <string>
using namespace std;

// Create struct
struct Student{
    int rollNumber;
    string fullName;
    float marks;

};

// Main functions
int main(){
    Student s; // Create pointer
    Student* s1 = &s;  // Create pointer to object
    // Assign stuff
    s1->rollNumber = 1;
    s1->fullName = "Muhammad Sumbul";
    s1->marks = 99.2;

    // Display all members
    cout << "Roll Number: " << s1->rollNumber << endl;
    cout << "Full Name: " << s1->fullName << endl;
    cout << "Marks: " << s1->marks << endl;

    // Get value
    cout<<"Enter new marks:\n";
    cin>>s1->marks;

    // Display all members
    cout<<"After changing marks"<<endl;
    cout << "Roll Number: " << s1->rollNumber << endl;
    cout << "Full Name: " << s1->fullName << endl;
    cout << "Marks: " << s1->marks << endl;
    
    // Free memory
    delete s1;
    s1 = nullptr;
}