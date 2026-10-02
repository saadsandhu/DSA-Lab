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
   void AddNode(int data);
   int CountNodes();
   void SearchNode(int searchData);
   void PrintSecondNode();
   void InsertAtBeginning(int addData);
   void DeleteNode(int delData);
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
    cout<<"NULL\n";
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

// Function to append node at the end
void List::AddNode(int addData){
   temp = new node;
   temp->data = addData;
   temp->next = NULL;

   if (head!=NULL){
      curr = head;
      while(curr->next!=NULL){
         curr = curr->next;
      }
      curr->next = temp;
   }
   else{
      head = temp;
   }

}

// Function to count the number of nodes
int List::CountNodes(){
    int count = 0;
    curr = head;
    while(curr!=NULL){ // Loop through the list
        count++;
        curr = curr->next; // Advance current
    }
    curr = nullptr;
    return count;
}

// Function to search for a value
void List::SearchNode(int searchData){
    int count = 1;
    curr = head;
    while(curr!=NULL && curr->data!= searchData){
        count++;
        curr = curr->next; // Advance current
    }
    if(curr == NULL){
        cout<<"Value not found\n";
    }
    else{ // Data found
        cout<<"The value was found at position "<<count<<endl;
    }

}

// Function to print the second node if exists
void List::PrintSecondNode(){
    // Second node is always head->next
    if(head==NULL || head->next==NULL){
        cout<<"List is empty or too short\n";
        return;
    }
    else{
        cout<<"Second Node: "<<head->next->data<<endl;
    }
}

// Function to insert at beginning
void List::InsertAtBeginning(int addData){
    temp = new node;
    temp->data = addData;
    temp->next = head;
    head = temp;
}

// Function to delete a node
void List::DeleteNode(int delData){
   curr = head;
   nodeptr prev = nullptr;

   while(curr!=NULL && curr->data!=delData){
    prev = curr;
    curr = curr->next;
   }
   if(curr==NULL){
    cout<<"Value not in list\n";
    curr = nullptr;
    return;
   }
   if (prev == nullptr){ // Value is at head
        head = curr->next;
    }
   else{
    prev->next = curr->next;
    }
    delete curr;
    curr = nullptr;
}

// Main function
int main(){
    List list;

    cout<<"Delete from empty list:\n";
    list.DeleteNode(10);

    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(20);
    list.AddNode(30);
    cout<<"Initial list:\n";
    list.PrintList();

    cout<<"Delete the first 20 (middle node):\n";
    list.DeleteNode(20);
    list.PrintList();

    cout<<"Delete a missing value:\n";
    list.DeleteNode(99);

    cout<<"Delete the first node:\n";
    list.DeleteNode(10);
    list.PrintList();

    cout<<"Delete the last node:\n";
    list.DeleteNode(30);
    list.PrintList();

    cout<<"Delete the only remaining node:\n";
    list.DeleteNode(20);
    list.PrintList();

    cout<<"Delete from the now-empty list:\n";
    list.DeleteNode(20);

    list.ClearList();
    return 0;
}