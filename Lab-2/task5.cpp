#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    if (n < 1 || n > 10) {
        cout << "Invalid n";
        return 0;
    }

    int* marks = new int[n];

    cout << "Enter " << n << " marks: ";
    for (int i = 0; i < n; i++) {
        cin >> *(marks + i);
    }

    // Allocate larger dynamic array
    int* newMarks = new int[n + 1];

    // Copy old values
    for (int i = 0; i < n; i++) {
        *(newMarks + i) = *(marks + i);
    }

    // Read new mark
    cout << "Enter new mark: ";
    cin >> *(newMarks + n);

    // Release old block
    delete[] marks;

    // Make original pointer point to new block
    marks = newMarks;
    n++; // n is now 1 more

    // Ouput
    cout << "Marks: ";
    for (int i = 0; i < n; i++) {
        cout << *(marks + i) << " ";
    }
    
    delete[] marks;
    marks = nullptr;
}