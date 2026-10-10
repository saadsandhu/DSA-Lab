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
   void DeleteNode(int value);
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

// Function to delete the first matching node
void CircularList::DeleteNode(int value){
    if(head==nullptr){
        cout<<"The list is empty"<<endl;
        return;
    }

    if(head==tail && head->data == value){
        delete head;
        head = nullptr;
        tail = nullptr;
        cout<<"Deleted value: "<<value<<endl;
        return;
    }

    nodeptr prev = tail;
    curr = head;
    do{
        if(curr->data == value){
            if(curr == head){
                head = head->next;
                tail->next = head;
            }
            else{
                prev->next = curr->next;
                if(curr == tail){
                    tail = prev;
                }
            }
            delete curr;
            cout<<"Deleted value: "<<value<<endl;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    while(curr!=head);

    cout<<"No matching value"<<endl;
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

    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(30);

    cout<<"Original list:\n";
    list.PrintList();
    cout<<"Original count: "<<list.CountNodes()<<endl;

    list.DeleteNode(10);
    cout<<"After deleting 10:\n";
    list.PrintList();
    cout<<"Count: "<<list.CountNodes()<<endl;

    list.DeleteNode(30);
    cout<<"After deleting 30:\n";
    list.PrintList();
    cout<<"Count: "<<list.CountNodes()<<endl;

    list.DeleteNode(20);
    cout<<"After deleting 20:\n";
    list.PrintList();
    cout<<"Count: "<<list.CountNodes()<<endl;

    list.ClearList();
    list.PrintList();
    return 0;
}
