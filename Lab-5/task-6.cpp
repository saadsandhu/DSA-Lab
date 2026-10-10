/*  Muhammad Saad
    548277
    BSCS-15D
    02/10/2026*/
#include <iostream>
using namespace std;

class LinkedStack {
private:
   typedef struct node{
      int data;
      node* next;
   }* nodeptr;

   nodeptr top;
   nodeptr curr;
   nodeptr temp;

public:
   LinkedStack();
   void Push(int value);
   int Pop();
   int Peek();
   bool IsEmpty();
   void Display();
   void ClearStack();
};

// Constructor
LinkedStack::LinkedStack(){
   top = nullptr;
   curr = nullptr;
   temp = nullptr;
}

// Function to push value onto the stack
void LinkedStack::Push(int value){
   temp = new node();
   temp->data = value;
   temp->next = top;
   top = temp;
}

// Function to pop value from the stack
int LinkedStack::Pop(){
   if(IsEmpty()){
      cout<<"The stack is empty"<<endl;
      return -1;
   }

   int poppedValue = top->data;
   temp = top;
   top = top->next;
   delete temp;
   return poppedValue;
}

// Function to read the top value without removing it
int LinkedStack::Peek(){
   if(IsEmpty()){
      cout<<"The stack is empty"<<endl;
      return -1;
   }

   return top->data;
}

// Function to check whether the stack is empty
bool LinkedStack::IsEmpty(){
   return top == nullptr;
}

// Function to display the stack
void LinkedStack::Display(){
   if(IsEmpty()){
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
void LinkedStack::ClearStack(){
   while(top!=nullptr){
      temp = top;
      top = top->next;
      delete temp;
   }
   curr = nullptr;
}

// Main function
int main(){
    LinkedStack stack;
    int choice;
    int value;

    do{
        cout<<"\nMenu\n";
        cout<<"1. Push\n";
        cout<<"2. Pop\n";
        cout<<"3. Peek\n";
        cout<<"4. Display\n";
        cout<<"5. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter value: ";
                cin>>value;
                stack.Push(value);
                break;
            case 2:
                value = stack.Pop();
                if(value != -1){
                    cout<<"Popped value: "<<value<<endl;
                }
                break;
            case 3:
                value = stack.Peek();
                if(value != -1){
                    cout<<"Top value: "<<value<<endl;
                }
                break;
            case 4:
                stack.Display();
                break;
            case 5:
                cout<<"Exiting program...\n";
                break;
            default:
                cout<<"Invalid choice"<<endl;
                break;
        }
    }
    while(choice != 5);

    stack.ClearStack();
    return 0;
}
