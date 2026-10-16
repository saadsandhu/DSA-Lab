/*  Muhammad Saad
    548277
    BSCS-15D
    16/10/2026*/
#include <iostream>
using namespace std;

class Stack {
private:
   typedef struct node{
      int data;
      node* next;
   }* nodeptr;

   nodeptr top;
   nodeptr curr;
   nodeptr temp;

public:
   Stack(){
    top = nullptr;
    curr = nullptr;
    temp = nullptr;
   }
    bool isEmpty(){
        return top==nullptr;
    } 

    void push(int value){
        temp = new node();
        temp->data = value;
        temp->next = top;
        top = temp;
    }

    void pop(){
        if(isEmpty()){
            cout<<"The stack is empty"<<endl;
        }

        int poppedValue = top->data;
        temp = top;
        cout<<"Popped: "<<top->data<<endl;
        top = top->next;
        delete temp;
    }

    void peek(){
        if(isEmpty()){
            cout<<"The stack is empty"<<endl;
            return;
        }

        cout<<"Peek: "<<top->data<<endl;
        }

    void display(){
    if(isEmpty()){
      cout<<"The stack is empty"<<endl;
      return;
   }

    curr = top;
    cout<<"Stack: ";
    while(curr!=nullptr){
        cout<<curr->data;
        if(curr->next != nullptr){
            cout<<"<-";
        }
        curr = curr->next;
    }
    cout<<endl;
    }

    // Function to clear the stack
    void clearStack(){
    while(top!=nullptr){
        temp = top;
        top = top->next;
        delete temp;
    }
    curr = nullptr;
}

};


void main(){
    Stack stack = Stack();
    stack.push(5);
    stack.push(15);
    stack.push(25);
    stack.display();
    stack.pop();
    stack.peek();

    
    // Test pop after empty
    stack.pop();
    stack.pop();
    stack.pop();

    stack.clearStack();



}
