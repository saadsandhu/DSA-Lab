/*  Muhammad Saad
    548277
    BSCS-15D
    02/10/2026*/
#include <iostream>
using namespace std;

class ArrayStack {
private:
   static const int MAX_SIZE = 10;
   int stack[MAX_SIZE];
   int top;

public:
   ArrayStack();
   void Push(int value);
   int Pop();
   int Peek();
   bool IsEmpty();
   bool IsFull();
   void Display();
   void ClearStack();
};

// Constructor
ArrayStack::ArrayStack(){
   top = -1;
}

// Function to push value onto the stack
void ArrayStack::Push(int value){
   if(IsFull()){
      cout<<"Stack is full"<<endl;
      return;
   }

   top++;
   stack[top] = value;
}

// Function to pop value from the stack
int ArrayStack::Pop(){
   if(IsEmpty()){
      cout<<"The stack is empty"<<endl;
      return -1;
   }

   int poppedValue = stack[top];
   top--;
   return poppedValue;
}

// Function to read the top value without removing it
int ArrayStack::Peek(){
   if(IsEmpty()){
      cout<<"The stack is empty"<<endl;
      return -1;
   }

   return stack[top];
}

// Function to check whether the stack is empty
bool ArrayStack::IsEmpty(){
   return top == -1;
}

// Function to check whether the stack is full
bool ArrayStack::IsFull(){
   return top == MAX_SIZE - 1;
}

// Function to display the stack
void ArrayStack::Display(){
   if(IsEmpty()){
      cout<<"The stack is empty"<<endl;
      return;
   }

   cout<<"Stack: ";
   for(int i=top;i>=0;i--){
      cout<<stack[i];
      if(i!=0){
         cout<<"<-";
      }
   }
   cout<<endl;
}

// Function to clear the stack
void ArrayStack::ClearStack(){
   top = -1;
}

// Main function
int main(){
    ArrayStack stack;

    stack.Push(10);
    stack.Push(20);
    stack.Push(30);

    cout<<"After pushing 10, 20, 30:\n";
    stack.Display();
    cout<<"Peek: "<<stack.Peek()<<endl;

    cout<<"Pop: "<<stack.Pop()<<endl;
    stack.Display();

    stack.ClearStack();
    cout<<"After clear:\n";
    stack.Display();

    return 0;
}
