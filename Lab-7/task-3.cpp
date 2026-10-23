/*  Muhammad Saad
    548277
    BSCS-15-D
    23/10/2026*/

// TASK 3
#include <iostream>
using namespace std;

// Array queue class
class CircularQueue{
private:
    static const int SIZE = 5;
    int queue[SIZE];
    int front;
    int rear;


public:
    // Constructor
    CircularQueue(){
        front = rear = -1;
    }

    // Queue is full when the next rear position is front
    bool IsFull(){
        return (rear+1)%SIZE==front;
    }

    // Queue is empty when front is at its default value
    bool IsEmpty(){
        return front == -1;
    }

    // Add value from rear
    void Enqueue(int value){
        if(IsFull()){
            cout<<"Cannot enqueue, Queue is full.\n";
            return;
        }

        if(IsEmpty()){
            front = 0;
        }

        rear = (rear+1)%SIZE; // Wrap around
        queue[rear] = value;
    }

    // Remove value from front
    void Dequeue(){
        if(IsEmpty()){
            cout << "Cannot dequeue.The Queue is empty\n";
            return;
        }
        
        cout<<"Dequeued: "<< queue[front]<<endl;

        if(front == rear){  // Last element
            front = -1;
            rear = -1;
        }
        else{
            front = (front + 1) % SIZE; // Wrap around
        }
    }

    // Display front value
    void Peek(){
        if(IsEmpty()){
                cout<<"Queue is empty.\n";
                return;
        }
        cout<<"Front value: "<<queue[front]<<endl;
    }

    // Display each value from front to rear, including after wraparound
    void Display() {
        if (IsEmpty()){
            cout<<"The queue is empty\n";
            return;
        }

        cout<<"Queue: ";
        for(int i=front;;i=(i+1)%SIZE){
            cout<<queue[i]<<" ";
            if(i==rear){ // Stop after displaying the rear value
                break;
            }
        }
        cout<<endl;
    }

};

int main(){
    // Initialize Queue
    CircularQueue queue;

    // Enqueue values
    queue.Enqueue(10);
    queue.Enqueue(20);
    queue.Enqueue(30);
    queue.Enqueue(40);
    queue.Enqueue(50);

    // Dequeue 10 and 20
    queue.Dequeue();
    queue.Dequeue();

    // Enqueue 60 and 70
    queue.Enqueue(60);
    queue.Enqueue(70);

    // Display
    queue.Display();

    // Reject insertion
    queue.Enqueue(80);

    // Empty the queue
    queue.Dequeue();
    queue.Dequeue();
    queue.Dequeue();
    queue.Dequeue();
    queue.Dequeue();

    // Dequeue on empty
    queue.Dequeue();

    // Insert on empty
    queue.Enqueue(90);

    queue.Display();

    return 0;
}