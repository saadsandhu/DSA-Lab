/*  Muhammad Saad
    548277
    BSCS-15-D
    23/10/2026*/

// TASK 2
#include <iostream>
using namespace std;

class LinkedQueue{
private:
    typedef struct node {
        int data;
        node* next;
    }* nodeptr;

    nodeptr front;
    nodeptr rear;

public:

    // Initialize an empty queue
    LinkedQueue(){
        front = rear = nullptr;
    }

    // Queue is empty when front points to nothing
    bool IsEmpty(){
        return front == nullptr;
    }

    // Add value from rear
    void Enqueue(int value){
        nodeptr temp = new node();
        temp->data = value;
        temp->next = nullptr;
        
        if(IsEmpty()){ // First value becomes both front and rear
            front = rear = temp;
        }
        else{
            rear->next = temp;
            rear = temp;
        }
    }

    // Remove value from front
    void Dequeue(){
        if(IsEmpty()){ // Return if empty
            cout<<"Cannot Dequeue, Queue is empty.\n";
            return;
        }

        cout<<"Dequeued: "<<front->data<<endl;
        nodeptr temp = front;
        front = temp->next;
        delete temp;

        if(front == nullptr){ // Reset rear when the last node is removed
            rear = nullptr;
        }
    }

    // Print value at front
    void Peek(){
        if(IsEmpty()){
                cout<<"Queue is empty.\n";
                return;
        }
        cout<<"Front value: "<< front->data<<endl;
        
    }

    // Display the entire queue
    void Display(){
        if(IsEmpty()){
            cout<<"Queue is empty.\n";
            return;
        }
        nodeptr curr = front;
        cout<<"Queue: ";
        while(curr!=nullptr){
            cout<<curr->data<<" ";
            curr = curr->next;
        }
        cout<<endl;
    }

    // Delete all remaining nodes
    void ClearQueue(){
        while(front != nullptr){
            nodeptr temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }
};


int main(){
    LinkedQueue queue;

    // Enqueue values
    queue.Enqueue(10);
    queue.Enqueue(20);
    queue.Enqueue(30);

    // Dequeue 10
    queue.Dequeue();

    // Display 20 and 30
    queue.Display();

    // Check peek 20
    queue.Peek();

    /// Clear the queue
    queue.Dequeue();
    queue.Dequeue();

    // Try dequeue on empty queue
    queue.Dequeue();

    // Test reuse
    queue.Enqueue(70);
    queue.Display();

    // Release any remaining nodes
    queue.ClearQueue();

    return 0;
}