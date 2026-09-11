#include <iostream>
using namespace std;

void move(int arr[],int index, int count){ // count will let us know which index to move to
    // Store the number that is to be moved
    int temp = arr[index];
    // Shift the array from count
    for(int i = index; i>count;i--){
        arr[i] = arr[i-1];

    }
    arr[count] = temp;
}

int main(){
    int numbers[10];
    
    cout<<"Enter 10 integers:\n";
    for(int i = 0; i<10; i++){
        cin>>numbers[i];
    }

    // Copy pasting the logic i made in task4

    int count = 0;
    for(int i = 0; i<10; i++){
        // Loop for checking the reapeating integers
        for(int j = 0; j<10; j++){
            if(j==i){
                continue;
            }
            if(numbers[i] == numbers[j]){
                if(j>i){ // Has not Already been reported
                    // Move the first occurence to the start
                    move(numbers,i,count);
                    count++;
                }
                break;
            }
        }
    }

    cout<< "Output Array"<<endl;
    for(int i = 0; i<10; i++){
        cout<<numbers[i]<<" ";
    }

    cout<<endl<<"Count= "<<count;

}