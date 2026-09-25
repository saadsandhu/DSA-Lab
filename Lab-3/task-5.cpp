/*Name: Muhammad Saad
  CMS: 548277
  Class: BSCS-15-D*/
  
#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rollNumber;
    string fullName;
    float marks;
};

void displayIfExists(const Student* s) {
    if (s != nullptr) {
        cout << "Roll Number: " << s->rollNumber << endl;
        cout << "Full Name: " << s->fullName << endl;
        cout << "Marks: " << s->marks << endl;
    }
    else {
        cout << "No record available" << endl;
    }
}

int main() {

    // Initialize pointer to nullptr
    Student* s1 = nullptr;

    // Before allocation
    displayIfExists(s1);

    // Allocate a student record
    s1 = new Student();

    // Input
    cout << "Enter roll number: ";
    cin >> s1->rollNumber;
    cout << "Enter full name: ";
    cin.ignore();
    getline(cin, s1->fullName);
    cout << "Enter marks: ";
    cin >> s1->marks;

    // After allocation
    displayIfExists(s1);

    // Delete record
    delete s1;
    s1 = nullptr;

    // After deletion
    displayIfExists(s1);

    return 0;
}