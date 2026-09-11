#include <iostream>
using namespace std;

class Student{
public:
    int rollNumber;
    int marks;

    void display(){
        cout<< "Roll Number: "<< rollNumber<< endl;
        cout<< "Marks: "<< marks<<endl;
    }
};

int main(){
    Student s1 = Student();
    s1.rollNumber = 1;
    s1.marks = 75;

    cout<< "s1:"<< endl;
    s1.display();

    Student s2 = Student();
    s2.rollNumber = 2;
    s2.marks = 90;
    cout<< "s2:"<< endl;
    s2.display();
    
    // Changin s1 marks
    s1.marks = 80;

    cout<<"After Change"<<endl;
    cout<< "s1:"<< endl;
    s1.display();
    cout<< "s2:"<< endl;
    s2.display();

}