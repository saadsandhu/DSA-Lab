/*  Muhammad Saad
    548277
    BSCS-15D
    16/10/2026*/
#include<iostream>
#include<string>
using namespace std;

class Stack{
private:
    static const int SIZE = 20;
    char items[SIZE];
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
        }
        char ch = items[top];
        top--;
        cout<<ch;
        
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

void reverse(string s){
    if(s.length()>20){
        cout<<"String must be less than 20 characters";
        return;
    }
    Stack stack = Stack();
    for(char ch:s){
        stack.push(ch);
    }
    while(!stack.isEmpty())
        stack.pop();

}

void main(){
    string s;
    cout<<"Enter word: ";
    cin>>s;

    reverse(s);

}
