/*  Muhammad Saad
    548277
    BSCS-15D
    02/10/2026*/
#include <iostream>
using namespace std;

class List{
private:
   typedef struct node{
      int data;
      node* next;

   }* nodeptr;

   nodeptr head;
   nodeptr curr;
   nodeptr temp;

public:
   List();
   void CreateThreeNodes();
   void PrintList();
   void ClearList();
};

// Constructor
List::List(){
   head = NULL;
   curr = NULL;
   temp = NULL;
}

// Function to make 3 new nodes from user inputs
void List::CreateThreeNodes(){ // Assuming the funciton is only called on an empty list
    for(int i=0;i<3;i++){ // Loop for all three values
        temp = new node; // Create new node
        cout<<"Enter Integer:\n";
        cin>>temp->data;    // Input
        temp->next = NULL; // Default

        if(i==0){ // If list was empty beforehand
            head = temp;
            curr = head;
        }
        else{ // Append new node
            curr->next = temp;
            curr = curr->next;
        }
    }
    temp = nullptr; // End of loop
}

// Function to print the entire list
void List::PrintList(){

    if(head==NULL){ // List is empty
        cout<<"The list is empty"<<endl;
        return;
    }

    curr = head;
    while(curr!=NULL){ // Loop through the list
        cout<<curr->data<<"->";
        curr = curr->next;
    }
    cout<<"NULL";
}

// Function to clear the entire list
void List::ClearList(){
    // Loop through all nodes and delete them
    curr = head;
    while(curr!=NULL){ // Loop through the list
        temp = curr; // Store node
        curr = curr->next; // Advance current
        delete temp;  // Delete node
    }
    head = nullptr; // Set head pointer to null
    temp = nullptr;
    curr = nullptr;
}

// Main function
int main(){
    List list;

    // Call printlist before creation
    list.PrintList();
    // Input the three values
    list.CreateThreeNodes();
    // Print again
    list.PrintList();

    list.ClearList();
    return 0;
}