#include <iostream>
using namespace std;

int main(){


    int row,col;

    cout<<"Enter number of students: ";
    cin>>row;
    cout<<"Enter number of subjects: ";
    cin>>col;

    if (row <= 0 || col <= 0) {
        cout << "Invalid dimensions";
        return 0;
    }

    int** marks = new int*[row];

    for(int r = 0;r<row;r++){
        marks[r] = new int[col];
        cout<<"Enter marks for Student "<<r+1<<": ";
        for(int c = 0;c<col;c++){
            cin>>*(*(marks + r) + c);
        }
    cout<<endl;
    }

    // Output
    for(int r = 0;r<row;r++){
        cout<<"Student "<<r+1<<": ";
        for(int c = 0;c<col;c++){
            cout<<*(*(marks + r) + c)<<" ";
        }
        cout<<endl;
    }

    // 4.
    // Student totals
    int total;
    int highest_total;
    int ht_student;
    for(int r = 0;r<row;r++){
        total = 0;
        for(int c = 0;c<col;c++){
            total += *(*(marks + r) + c);
        }
        if(r==0){ // First student
            highest_total = total;
            ht_student = r+1;
        }
        else if(total>highest_total){
            highest_total = total;
            ht_student = r+1;
        }
        cout<<"Student "<<r+1<<" Total: "<< total<<endl;
    }

    cout << "Student "<<ht_student<<" has highest total marks: "<< highest_total<<endl;

    // 5.

    for(int r = 0;r<row;r++)
        delete[] marks[r];
    
    delete[] marks;
    marks = nullptr;
}