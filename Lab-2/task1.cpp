#include <iostream>
using namespace std;

int main(){
    // 1.
    int sales[5];
    int* p = sales;
    // Read values
    cout<<"Enter 5 integers twin:\n";
    for(int i=0;i<5;i++){
        cin>>*(p+i);
    }

    int total = 0;
    // Output values
    cout<<"Array Elements: ";
    for(int i=0;i<5;i++){
        cout<<*(p+i)<<" ";
        total += *(p+i);
    }
    cout<<"\nTotal: "<<total<<endl;


    // 2.
    // Add 2 to third day value
    *(p+2) = *(p+2)+2;

    // Show updated values and total
    total = 0;
    cout<<"Updated Array Elements: ";
    for(int i=0;i<5;i++){
        cout<<*(p+i)<<" ";
        total += *(p+i);
    }
    cout<<"\nUpdated Total: "<<total;
}