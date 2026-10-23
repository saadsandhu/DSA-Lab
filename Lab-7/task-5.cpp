/*  Muhammad Saad
    548277
    BSCS-15-D
    23/10/2026*/

// TASK 5
#include <iostream>
using namespace std;

// Circular array deque class
class ArrayDeque{
private:
    static const int SIZE = 5;
    int deque[SIZE];
    int front;
    int rear;

public:
    // Constructor
    ArrayDeque(){
        front = rear = -1;
    }

    // Deque is full when the next rear position is front
    bool IsFull(){
        return (rear+1)%SIZE==front;
    }

    // Deque is empty when front is at its default value
    bool IsEmpty(){
        return front == -1;
    }

    // Add value at front
    void InsertFront(int value){
        if(IsFull()){ // Return if full
            cout<<"Cannot insert at front, Deque is full.\n";
            return;
        }

        if(IsEmpty()){ // First value starts at index 0
            front = rear = 0;
        }
        else{
            front = (front+SIZE-1)%SIZE;
        }
        deque[front] = value;
    }

    // Add value at rear
    void InsertRear(int value){
        if(IsFull()){ // Return if full
            cout<<"Cannot insert at rear, Deque is full.\n";
            return;
        }

        if(IsEmpty()){ // First value starts at index 0
            front = rear = 0;
        }
        else{
            rear = (rear+1)%SIZE;
        }
        deque[rear] = value;
    }

    // Remove value from front
    void DeleteFront(){
        if(IsEmpty()){ // Return if empty
            cout<<"Cannot delete from front, Deque is empty.\n";
            return;
        }

        cout<<"Deleted from front: "<<deque[front]<<endl;
        if(front == rear){ // Last element, reset both indices
            front = rear = -1;
        }
        else{
            front = (front+1)%SIZE;
        }
    }

    // Remove value from rear
    void DeleteRear(){
        if(IsEmpty()){ // Return if empty
            cout<<"Cannot delete from rear, Deque is empty.\n";
            return;
        }

        cout<<"Deleted from rear: "<<deque[rear]<<endl;
        if(front == rear){ // Last element, reset both indices
            front = rear = -1;
        }
        else{
            rear = (rear+SIZE-1)%SIZE;
        }
    }

    // Display the entire deque from front to rear
    void Display(){
        if(IsEmpty()){
            cout<<"The deque is empty\n";
            return;
        }

        cout<<"Deque: ";
        for(int i=front;;i=(i+1)%SIZE){
            cout<<deque[i]<<" ";
            if(i==rear){
                break;
            }
        }
        cout<<endl;
    }
};

int main(){
    ArrayDeque deque;

    // Insert 20 at rear, 10 at front, and 30 at rear
    deque.InsertRear(20);
    deque.InsertFront(10);
    deque.InsertRear(30);
    deque.Display();

    // Delete from rear, then front
    deque.DeleteRear();
    deque.DeleteFront();
    deque.Display();

    // Fill the deque and test insertion at both ends
    deque.InsertFront(5);
    deque.InsertRear(30);
    deque.InsertRear(40);
    deque.InsertFront(1);
    deque.Display();
    deque.InsertFront(0);
    deque.InsertRear(50);

    // Test deleting the only value from the front
    ArrayDeque deleteFrontTest;
    deleteFrontTest.InsertRear(10);
    deleteFrontTest.DeleteFront();
    deleteFrontTest.DeleteFront();

    // Test deleting the only value from the rear
    ArrayDeque deleteRearTest;
    deleteRearTest.InsertFront(20);
    deleteRearTest.DeleteRear();
    deleteRearTest.DeleteRear();

    return 0;
}
