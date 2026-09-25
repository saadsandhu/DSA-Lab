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
    Student* s1 = new Student();  // Create pointer to object
    
    // Input values
    cout<<"Enter roll number:\n";
    cin>>s1->rollNumber;
    cout<<"Enter full name:\n";
    cin.ignore(); // Ignore the newline character left in the input buffer
    getline(cin, s1->fullName); // Use getline to read the full name with spaces
    cout<<"Enter marks:\n";
    cin>>s1->marks;

    // Display all members
    cout << "Roll Number: " << s1->rollNumber << endl;
    cout << "Full Name: " << s1->fullName << endl;
    cout << "Marks: " << s1->marks << endl;

    // Free memory
    delete s1;
    s1 = nullptr;
}