/*  Muhammad Saad
    548277
    BSCS-15D
    16/10/2026*/
#include<iostream>
using namespace std;

class Stack{
private:
    static const int SIZE = 5;
    int items[SIZE];
    int top;

public:
    Stack(){
        top = -1;
    }

    bool isEmpty(){
        return top==-1;
    }
    bool isFull(){
        return top==SIZE-1;
    }

    // Funtion to push value
    void push(int value){
       if(isFull()){
        cout<<"Stack is full\n";
       }

       else{
        top++;
        items[top] = value;
       }
    }

    // Function to pop value
    void pop(){
        if(isEmpty()){
            cout<<"Stack is empty\n";
            return;
        }

        cout<<"Popped: "<<items[top]<<endl;
        top--;
        
    }

    // Function to peek top value
    void peek(){
        if(isEmpty()){
            cout<<"Stack is empty\n";
            return;
        }
        cout<<"Peek: "<<items[top]<<endl;
    }

    void display(){
        if(isEmpty()){
            cout<<"The stack is empty\n"<<endl;
            return;
        }

        cout<<"Stack: ";
        for(int i=top;i>=0;i--){
            cout<<items[i];
            if(i!=0){
                cout<<"<-";
            }
        }
        cout<<endl;
    }
};

void main(){
    Stack stack = Stack();
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();
    stack.pop();
    stack.peek();

    // Test 6th insertion
    stack.push(40);
    stack.push(50);
    stack.push(60);
    stack.push(70);
    
    // Test pop after empty
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();



}
