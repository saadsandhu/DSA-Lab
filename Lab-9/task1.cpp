/*  Lab 9
    Muhammad Saad
    13/11/2026*/

#include <iostream>
#include <queue>
#include <string>
using namespace std;

/* The BST keeps students ordered by roll number, and the queue serves help
   requests in arrival order (FIFO).
   Adding a student to the BST: O(n) worst case , O(logn) Average case
   Searching the BST: O(n) worst case. O(logn) Average case */

// Node for BST
struct StudentNode{
    int rollno; // Rollno will be used to add to BST
    string name;
    
    StudentNode* left;
    StudentNode* right;

    StudentNode(int roll, const string& studentName){ // Constructor
        rollno = roll;
        name = studentName;
        left = nullptr;
        right = nullptr;
    }
};

StudentNode* insertStudent(StudentNode* root, int rollno, const string& name, bool& inserted){ // bool inserted is used to check if it was successfully added
    // Inserted is passed as false when the function is first called
    if (root == nullptr) { // If root is null insert the node, Base condition
        inserted = true;
        return new StudentNode(rollno, name);
    }

    // Recursive calls
    if (rollno < root->rollno) {
        root->left = insertStudent(root->left, rollno, name, inserted);
    } else if (rollno > root->rollno) {
        root->right = insertStudent(root->right, rollno, name, inserted);
    }
    // If neither match, value is equal, inserted is false

    return root;
}

StudentNode* searchStudent(StudentNode* root, int rollno){
    while (root != nullptr){
        if (rollno == root->rollno){ // If matched return
            return root;
        }
        if (rollno < root->rollno){  // If less than root go left
            root = root->left;
        }
        else{
            root = root->right; // If greater than root go right
        }
    }
    return nullptr; // If not found
}

// Print all nodes
void displayStudents(StudentNode* root){
    if (root == nullptr){  // Base condition
        return;
    }

    displayStudents(root->left);    // Recursive call to left node
    cout << "Roll number: " << root->rollno << ", Name: " << root->name << '\n';
    displayStudents(root->right); // Recursive call to right node
}

// Clear all records
void deleteStudents(StudentNode* root){
    if (root == nullptr){ // Base condition
        return;
    }

    deleteStudents(root->left); // Recursive call to left node
    deleteStudents(root->right);    // Recursive call to right node
    delete root;
}

// Task 2 : Additional feature : Help Request
void helpRequests(StudentNode* root, queue<int>& requests){
    int choice;

    do {
        cout << "\nHelp Requests Menu:\n"
             << "1. Add help request\n"
             << "2. Serve earliest request\n"
             << "3. Return to main menu\n"
             << "Enter choice: ";
        cin >> choice;

        if (choice == 1){
            int rollno;
            cout << "Enter student roll number: ";
            cin >> rollno;

            StudentNode* student = searchStudent(root, rollno);
            if (student == nullptr){
                cout << "No registered student has that roll number.\n";
            }
            else{
                requests.push(rollno); // Add new request
                cout << "Help request added for " << student->name << ".\n";
            }
        }
        else if (choice == 2){
            if (requests.empty()){
                cout << "There are no waiting help requests.\n";
            }
            else{
                int rollno = requests.front();
                requests.pop(); // Remove first Request
                StudentNode* student = searchStudent(root, rollno);
                cout << "Serving " << student->name << " (roll number "
                     << rollno << ").\n";
            }
        } 
        else if (choice != 3){ // If anything other than 2 choices or exit
            cout << "Invalid choice. Try again.\n";
        }
    }
    while (choice != 3);
}

int main(){
    StudentNode* root = nullptr;
    queue<int> helpRequestsqueue;
    int choice;

    do{
        cout << "\nMain Menu:\n"
             << "1. Add student\n"
             << "2. Search student\n"
             << "3. Display all students\n"
             << "4. Manage help requests\n"
             << "5. Exit\n"
             << "Enter choice: ";
        cin >> choice;

        if (choice == 1){
            int rollno;
            string name;
            cout << "Enter roll number: ";
            cin >> rollno;
            cout << "Enter student name: ";
            cin >> ws;
            getline(cin, name);

            bool inserted = false;
            root = insertStudent(root, rollno, name, inserted);
            if (inserted){
                cout << "Student added successfully.\n";
            }
            else{
                cout << "A student with that roll number already exists.\n";
            }
        }
        else if (choice == 2){
            int rollno;
            cout << "Enter roll number to search: ";
            cin >> rollno;

            StudentNode* student = searchStudent(root, rollno);
            if (student == nullptr){
                cout << "Student not found.\n";
            }
            else{
                cout << "Student found: " << student->name
                     << " (roll number " << student->rollno << ").\n";
            }
        }
        else if (choice == 3){
            if (root == nullptr){
                cout << "No students are registered.\n";
            }
            else{
                displayStudents(root);
            }
        }
        else if (choice == 4){
            helpRequests(root, helpRequestsqueue);
        }
        else if (choice == 5){
            cout << "Exiting the student help desk.\n";
        }
        else{
            cout << "Invalid choice. Try again.\n";
        }
    }
    while (choice != 5); // If not invalid choice

    deleteStudents(root); // Clear memory before exiting
    return 0;
}
