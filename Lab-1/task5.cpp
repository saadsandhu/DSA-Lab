#include <iostream>
using namespace std;

void reverse(int arr[],int si=0,int ei=5){ // si = Start Index, ei = End Index
    if(si > ei)
        return;
    else{
        int temp = arr[si];
        arr[si] = arr[ei];
        arr[ei] = temp;
        reverse(arr,si+1,ei-1); // Dont need to return, array is passed as pointer
    }
}

int main(){
    int numbers[6];

    cout<<"Enter 6 integers:\n";
    for(int i = 0; i<6; i++){
        cin>>numbers[i];
    }

    cout<< "Original Array"<<endl;
    for(int i = 0; i<6; i++){
        cout<<numbers[i]<<" ";
    }

    reverse(numbers);

    cout<<endl << "Reversed Array"<<endl;
    for(int i = 0; i<6; i++){
        cout<<numbers[i]<<" ";
    }
}
