/*  Muhammad Saad
    548277
    BSCS-15D
    10/10/2026*/
#include <iostream>
using namespace std;

class DoublyList{
private:
   typedef struct node{
      int data;
      node* next;
      node* prev;

   }* nodeptr;

   nodeptr head;
   nodeptr curr;
   nodeptr temp;
   nodeptr tail;
   nodeptr prev;

public:
   DoublyList();
   void AddNode(int value);
   void PrintForward();
   void PrintReverse();
   void ClearList();
};

// Constructor
DoublyList::DoublyList(){
   head = nullptr;
   tail = nullptr;
   curr = nullptr;
   temp = nullptr;
   prev = nullptr;
}

// Function to append value at the end
void DoublyList::AddNode(int value){
    temp = new node();
    temp->data = value;
    temp->prev = tail;
    if(tail!=nullptr){
        tail->next = temp;
    }
    tail = temp;
    if(head==nullptr){
        head = temp;
    }

}

// Function to print list from head to tail
void DoublyList::PrintForward(){
    if(head==nullptr){ // List is empty
        cout<<"The list is empty"<<endl;
        return;
    }

    curr = head;
    while(curr!=nullptr){ // Loop through the list
        cout<<curr->data<<"->";
        curr = curr->next;
    }
    cout<<"NULL\n";

}

// Function to print list from head to tail
void DoublyList::PrintReverse(){
    if(tail==nullptr){ // List is empty
        cout<<"The list is empty"<<endl;
        return;
    }

    curr = tail;
    while(curr!=nullptr){ // Loop through the list
        cout<<curr->data<<"->";
        curr = curr->prev;
    }
    cout<<"NULL\n";

}

// Function to clear the entire list
void DoublyList::ClearList(){
    // Loop through all nodes and delete them
    curr = head;
    while(curr!=nullptr){ // Loop through the list
        temp = curr; // Store node
        curr = curr->next; // Advance current
        delete temp;  // Delete node
    }
    head = nullptr; // Set head pointer to null
    tail = nullptr;
    temp = nullptr;
    curr = nullptr;
}

// Main function
int main(){
    DoublyList list;

    int n;
    int temp;
    // Call printlist before adding values
    list.PrintForward();
    // Input the values
    cout<<"Enter number of integers: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter integer: ";
        cin>>temp;
        list.AddNode(temp);
    }

    // Print again
    cout<<"Forward:\n";
    list.PrintForward();
    cout<<"Reverse:\n";
    list.PrintReverse();

    list.ClearList();
    cout<<"After Clear";
    list.PrintForward();
    return 0;
}