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

int main() {

    // Function declarations inside main
    void displayStudent(const Student* s);
    void updateMarks(Student* s, float newMarks);

    Student* s1 = new Student();

    cout << "Enter roll number: ";
    cin >> s1->rollNumber;

    cout << "Enter full name: ";
    cin.ignore();
    getline(cin, s1->fullName);

    cout << "Enter marks: ";
    cin >> s1->marks;

    displayStudent(s1);

    updateMarks(s1, 95.5);

    cout << "After updating marks:" << endl;
    displayStudent(s1);

    delete s1;
    s1 = nullptr;

}

// Function definitions
void displayStudent(const Student* s) {
    cout << "Roll Number: " << s->rollNumber << endl;
    cout << "Full Name: " << s->fullName << endl;
    cout << "Marks: " << s->marks << endl;
}

void updateMarks(Student* s, float newMarks) {
    s->marks = newMarks;
}