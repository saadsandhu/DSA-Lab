#include <iostream>
using namespace std;

int main(){
    int sales[2][3];
    int (*rowPtr)[3] = sales;
    
    // 1.
    // Read
    for(int r = 0;r<2;r++){
        cout<<"Enter sales for Branch "<<r+1<<": ";
        for(int c = 0;c<3;c++){
            cin>>*(*(rowPtr + r) + c);
        }
        cout<<endl;
    }

    // Output
    for(int r = 0;r<2;r++){
        cout<<"Branch "<<r+1<<": ";
        for(int c = 0;c<3;c++){
            cout<<*(*(rowPtr + r) + c)<<" ";
        }
        cout<<endl;
    }

    // 2.
    // Branch totals
    int total;
    for(int r = 0;r<2;r++){
        total = 0;
        for(int c = 0;c<3;c++){
            total += *(*(rowPtr + r) + c);
        }
        cout<<"Branch "<<r+1<<" Total: "<< total<<endl;
    }

    // Day totals
    for(int c = 0;c<3;c++){
        total = 0;
        for(int r = 0;r<2;r++){
            total += *(*(rowPtr + r) + c);
        }
        cout<<"Day "<<c+1<<" Total: "<< total<<endl;
    }

}