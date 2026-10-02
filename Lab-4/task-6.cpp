/*  Muhammad Saad
    548277
    BSCS-15D
    02/10/2026*/
#include <iostream>
using namespace std;

class List{
private:
   struct node{
      int data;
      node* next;
   };

   node* head;

public:
   List();
   void InsertAtBeginning(int addData);
   void AddNode(int addData);
   void SearchNode(int searchData) const;
   void DeleteNode(int delData);
   void PrintList() const;
   int CountNodes() const;
   void PrintSecondNode() const;
   void ClearList();
};

List::List() : head(nullptr) {}

void List::InsertAtBeginning(int addData){
   node* newNode = new node;
   newNode->data = addData;
   newNode->next = head;
   head = newNode;
}

void List::AddNode(int addData){
   node* newNode = new node;
   newNode->data = addData;
   newNode->next = nullptr;

   if(head == nullptr){
      head = newNode;
      return;
   }

   node* curr = head;
   while(curr->next != nullptr){
      curr = curr->next;
   }
   curr->next = newNode;
}

void List::SearchNode(int searchData) const{
   const node* curr = head;
   int position = 1;
   while(curr != nullptr && curr->data != searchData){
      curr = curr->next;
      position++;
   }

   if(curr == nullptr){
      cout<<"Value not found\n";
   }
   else{
      cout<<"The value was found at position "<<position<<'\n';
   }
}

void List::DeleteNode(int delData){
   node* curr = head;
   node* prev = nullptr;
   while(curr != nullptr && curr->data != delData){
      prev = curr;
      curr = curr->next;
   }

   if(curr == nullptr){
      cout<<"Value not in list\n";
      return;
   }

   if(prev == nullptr){
      head = curr->next;
   }
   else{
      prev->next = curr->next;
   }
   delete curr;
}

void List::PrintList() const{
   if(head == nullptr){
      cout<<"The list is empty\n";
      return;
   }

   const node* curr = head;
   while(curr != nullptr){
      cout<<curr->data<<"->";
      curr = curr->next;
   }
   cout<<"NULL\n";
}

int List::CountNodes() const{
   int count = 0;
   const node* curr = head;
   while(curr != nullptr){
      count++;
      curr = curr->next;
   }
   return count;
}

void List::PrintSecondNode() const{
   if(head == nullptr || head->next == nullptr){
      cout<<"List is empty or too short\n";
      return;
   }
   cout<<"Second Node: "<<head->next->data<<'\n';
}

void List::ClearList(){
   while(head != nullptr){
      node* next = head->next;
      delete head;
      head = next;
   }
}

int main(){
   List list;
   bool running = true;

   while(running){
      int choice;
      cout<<"\nLinked List Menu\n"
          <<"1. Insert at the beginning\n"
          <<"2. Insert at the end\n"
          <<"3. Search by value\n"
          <<"4. Delete by value\n"
          <<"5. Display all nodes\n"
          <<"6. Count nodes\n"
          <<"7. Display the second node\n"
          <<"8. Exit\n"
          <<"Enter your choice: ";
      cin>>choice;

      int value;
      switch(choice){
         case 1:
            cout<<"Enter integer: ";
            cin>>value;
            list.InsertAtBeginning(value);
            break;
         case 2:
            cout<<"Enter integer: ";
            cin>>value;
            list.AddNode(value);
            break;
         case 3:
            cout<<"Enter value to search: ";
            cin>>value;
            list.SearchNode(value);
            break;
         case 4:
            cout<<"Enter value to delete: ";
            cin>>value;
            list.DeleteNode(value);
            break;
         case 5:
            list.PrintList();
            break;
         case 6:
            cout<<"The list has "<<list.CountNodes()<<" nodes\n";
            break;
         case 7:
            list.PrintSecondNode();
            break;
         case 8:
            running = false;
            break;
         default:
            cout<<"Invalid menu choice\n";
            break;
      }
   }

   list.ClearList();
   return 0;
}
