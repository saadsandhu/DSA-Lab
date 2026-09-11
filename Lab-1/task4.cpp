#include <iostream>
using namespace std;

int main(){
    int numbers[8];
    
    cout<<"Enter 8 integers:\n";
    for(int i = 0; i<8; i++){
        cin>>numbers[i];
    }

    int largest = numbers[0];
    int smallest = numbers[0];

    for(int i = 0; i<8; i++){
        if(numbers[i]>largest)
            largest = numbers[i];
        if(numbers[i]<smallest)
            smallest = numbers[i];

        // Loop for checking the reapeating integers
        for(int j = 0; j<8; j++){
            if(j==i){
                continue;
            }
            if(numbers[i] == numbers[j]){
                if(j>i){ // Has not Already been reported
                    cout<<numbers[i]<<" is repeated. "<<"First occurence of "<<numbers[i]<< " is at "<<" index "<<i<<endl;
                }
                break;
            }
        }
    }

    cout<< "Largest number is "<<largest<<endl;
    cout<< "Smallest number is "<<smallest<<endl;
}