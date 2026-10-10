/*  Muhammad Saad
    548277
    BSCS-15D
    02/10/2026*/
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
   void InsertBefore(int position, int value);
   void DeleteNode(int value);
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

// Function to print list fro/m head to tail
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

// Function to add before a postion
void DoublyList::InsertBefore(int position, int value){
    curr = head;
    int count = 1;
    if(position<1){
        cout<<"Invalid Position\n";
        return;
    }
    while(curr!=nullptr && count<position){
        curr = curr->next;
        count++;
    }
    if(curr==nullptr){
        cout<<"Invalid Position\n";
        return;
    } 
    
    temp = new node();
    temp->data = value;

    temp->next = curr;
    if(curr->prev!=nullptr){
        temp->prev=curr->prev;
        curr->prev->next = temp;
    }
    if(curr==head){
        head = temp;
    }

    curr->prev = temp;

}

// Function to delete node from value
void DoublyList::DeleteNode(int value){
    curr = head;
    while(curr!=nullptr && curr->data != value){
        curr = curr->next;
    }
    if (curr==nullptr){
        cout<<"No matching value\n";
        return;
    }
    else{
        prev = curr->prev;

        if(curr==head){
            head = curr->next;
        }
        else{
            prev->next = curr->next;
        }
        if(curr==tail){
            tail = curr->prev;
        }
        else{
            curr->next->prev = prev;
        }

        delete curr;
        curr = nullptr;
        

    }
}

// Main function
int main(){
    DoublyList list;

    // Input the values
    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(30);

    list.InsertBefore(2,15);

    // Print again
    cout<<"Forward:\n";
    list.PrintForward();
    cout<<"Reverse:\n";
    list.PrintReverse();

    list.DeleteNode(10);
    cout<<"\nAfter Deleteion\n";
    cout<<"Forward:\n";
    list.PrintForward();
    cout<<"Reverse:\n";
    list.PrintReverse();

    list.ClearList();
    return 0;
}