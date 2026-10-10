/*  Muhammad Saad
    548277
    BSCS-15D
    02/10/2026*/
#include <iostream>
using namespace std;

class CircularList {
private:
   typedef struct node{
      int data;
      node* next;

   }* nodeptr;

   nodeptr head;
   nodeptr curr;
   nodeptr temp;
   nodeptr tail;

public:
   CircularList();
   void AddNode(int value);
   void PrintList();
   int CountNodes();
   void ClearList();
};

// Constructor
CircularList::CircularList(){
   head = nullptr;
   tail = nullptr;
   curr = nullptr;
   temp = nullptr;
}

// Function to append node at the end
void CircularList::AddNode(int value){
   temp = new node();
   temp->data = value;
   temp->next = nullptr;

   if(head == nullptr){
      head = temp;
      tail = temp;
      temp->next = head;
   }
   else{
      tail->next = temp;
      temp->next = head;
      tail = temp;
   }
}

// Function to print the entire list
void CircularList::PrintList(){
    if(head==nullptr){ // List is empty
        cout<<"The list is empty"<<endl;
        return;
    }

    curr = head;
    do{ // Loop through the list until one full cycle is complete
        cout<<curr->data<<"->";
        curr = curr->next;
    }
    while(curr!=head);
    cout<<"NULL\n";
}

// Function to count the number of nodes
int CircularList::CountNodes(){
    if(head==nullptr){
        return 0;
    }

    int count = 0;
    curr = head;
    do{ // Loop through the list until one full cycle is complete
        count++;
        curr = curr->next;
    }
    while(curr!=head);
    curr = nullptr;
    return count;
}

// Function to clear the entire list
void CircularList::ClearList(){
    if(head==nullptr){
        return;
    }

    tail->next = nullptr;
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
    CircularList list;

    int n;
    int data;

    cout<<"Enter number of integers: ";
    cin>>n;

    list.PrintList();
    for(int i=0;i<n;i++){ // Loop n times
        cout<<"Enter Integer: ";
        cin>>data;

        // Add the node
        list.AddNode(data);
    }

    cout<<"Final list:\n";
    list.PrintList();
    cout<<"Number of nodes: "<<list.CountNodes()<<'\n';
    list.ClearList();
    return 0;
}