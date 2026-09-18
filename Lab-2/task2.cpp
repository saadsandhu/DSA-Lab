#include <iostream>
using namespace std;

int main(){
    // 1.
    int n;
    cout<<"Enter number of students(n): ";
    cin>>n;

    if(n<=0){
        cout<<"Error; no allocation or mark input";
        return 0;
    }

    // Declare Dynamic array
    int* marks = new int[n];
    // Read into array
    cout<<"Enter marks: ";
    for(int i = 0;i<n;i++){
        cin>>*(marks+i);
    }

    // 2.
    int total = 0;
    int pass = 0;
    float avg;

    cout<<"Entered Marks:";
    for(int i = 0;i<n;i++){
        cout<<*(marks+i)<<" ";
        total += *(marks+i);
        if(*(marks+i)>=50){
            pass++;
        }
    }

    avg = (float)total/n;

    cout<<"\nTotal: "<<total;
    cout<<"\nAverage: "<<avg;
    cout<<"\nPass count: "<<pass;

    // 3.
    delete[] marks;
    marks = nullptr;
}