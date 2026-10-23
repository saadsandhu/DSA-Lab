/*  Muhammad Saad
    548277
    BSCS-15-D
    23/10/2026*/

// TASK 1
#include <iostream>
using namespace std;

// Array queue class
class ArrayQueue{
private:
    static const int SIZE = 5;
    int queue[SIZE];
    int front;
    int rear;


public:
    // Constructor
    ArrayQueue(){
        front = rear = -1;
    }

    // Queue is full when index of rear equal to size-1
    bool IsFull(){
        return rear == SIZE - 1;
    }

    // Queue is empty when both indices at default
    bool IsEmpty(){
        return rear == -1 && front == -1;
    }

    // Add value from rear
    void Enqueue(int value){
        if(IsFull()){ // Return if full
            cout<<"Cannot enqueue, Queue is full.\n";
            return;
        }
        if(IsEmpty()){ // If first value set front to 0, rear gets set automatically
            front = 0;
        }
        rear++;
        queue[rear] = value;
    }

    void Dequeue(){
        if(IsEmpty()){ // Return if empty
            cout << "Cannot dequeue.The Queue is empty\n";
            return;
        }
        
        cout<<"Dequeued: "<< queue[front]<<endl;

        if(front == rear){  // Last element, set front and rear to default
            front = -1;
            rear = -1;
        } 
        else{
            front++;
        }

    }

    // Print value at front
    void Peek(){
        if(IsEmpty()){
                cout<<"Queue is empty.\n";
                return;
        }
        cout<<"Front value: "<<queue[front]<<endl;
    }

    // Display the enitre queue
    void Display() {
    if (IsEmpty()){
        cout<<"The queue is empty\n";
        return;
    }

    cout<<"Queue: ";
    for(int i=front;i<=rear;i++){
        cout<<queue[i]<<" ";
    }
    cout<<endl;
}

};

int main(){
    ArrayQueue queue;

    // Enqueue values
    queue.Enqueue(10);
    queue.Enqueue(20);
    queue.Enqueue(30);
    queue.Enqueue(40);
    queue.Enqueue(50);

    // Dequeue 10 and 20
    queue.Dequeue();
    queue.Dequeue();

    // Reject insertion because the linear queue has reached the end of the array
    queue.Enqueue(60);

    // Display
    queue.Display();

    /// Clear the queue
    queue.Dequeue();
    queue.Dequeue();
    queue.Dequeue();

    // Try dequeue on empty queue
    queue.Dequeue();

    // Test reuse
    queue.Enqueue(70);
    queue.Display();

    return 0;
}