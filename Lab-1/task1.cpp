#include <iostream>
using namespace std;

int main(){
    int numbers[5] = {2,4,6,8,10};
    numbers[2] = 7; // Third element, second index
    for(int number : numbers){
        cout<<number<<" ";
    }
}