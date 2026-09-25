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
    Student s1; // Make object
    // Assign stuff
    s1.rollNumber = 1;
    s1.fullName = "Muhammad Sumbul";
    s1.marks = 99.2;

    // Display all members
    cout << "Roll Number: " << s1.rollNumber << endl;
    cout << "Full Name: " << s1.fullName << endl;
    cout << "Marks: " << s1.marks << endl;


}