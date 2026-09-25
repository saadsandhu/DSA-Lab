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
        cout << "\nRoll Number: " << s->rollNumber << endl;
        cout << "Full Name: " << s->fullName << endl;
        cout << "Marks: " << s->marks << endl;
    }
    else {
        cout << "\nNo record available" << endl;
    }
}

void updateMarks(Student* s, float newMarks) {
    if (s != nullptr) {
        s->marks = newMarks;
        cout << "Marks updated successfully.\n";
    }
    else {
        cout << "No record available.\n";
    }
}

int main() {

    Student* s1 = nullptr;

    int choice;

    do {
        cout << "\nStudent Record Menu" << endl;
        cout << "1. Create Record" << endl;
        cout << "2. Display Record" << endl;
        cout << "3. Update Marks" << endl;
        cout << "4. Delete Record" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Prevent creating another record
                if (s1 != nullptr) {
                    cout << "A record already exists. Cannot create another.\n";
                }
                else {
                    s1 = new Student();

                    cout << "Enter roll number: ";
                    cin >> s1->rollNumber;

                    cout << "Enter full name: ";
                    cin.ignore();
                    getline(cin, s1->fullName);

                    cout << "Enter marks: ";
                    cin >> s1->marks;

                    cout << "Record created successfully.\n";
                }
                break;

            case 2:
                // Display only if record exists
                displayIfExists(s1);
                break;

            case 3:
                if (s1 != nullptr) {
                    float newMarks;

                    cout << "Enter new marks: ";
                    cin >> newMarks;

                    updateMarks(s1, newMarks);
                }
                else {
                    cout << "No record available.\n";
                }
                break;

            case 4:
                // Delete only if record exists
                if (s1 != nullptr) {
                    delete s1;
                    s1 = nullptr;

                    cout << "Record deleted successfully.\n";
                }
                else {
                    cout << "No record available to delete.\n";
                }
                break;

            case 5:
                cout << "Exiting program\n";
                break;

            default:
                cout << "Invalid choice. Please enter 1-5.\n";
        }

    } while (choice != 5);

    // Release any remaining allocation before exiting
    if (s1 != nullptr) {
        delete s1;
        s1 = nullptr;
    }

}