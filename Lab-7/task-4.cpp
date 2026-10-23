/*  Muhammad Saad
    548277
    BSCS-15-D
    23/10/2026*/

// TASK 4
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
        if(IsFull()){ // Return if full
            cout<<"Cannot enqueue, Queue is full.\n";
            return;
        }

        if(IsEmpty()){ // First value starts at index 0
            front = 0;
        }

        rear = (rear+1)%SIZE;
        queue[rear] = value;
    }

    // Remove value from front
    void Dequeue(){
        if(IsEmpty()){ // Return if empty
            cout<<"Cannot dequeue, Queue is empty.\n";
            return;
        }

        cout<<"Dequeued: "<<queue[front]<<endl;

        if(front == rear){ // Last element, reset both indices
            front = -1;
            rear = -1;
        }
        else{
            front = (front+1)%SIZE;
        }
    }

    // Display the entire queue
    void Display(){
        if(IsEmpty()){
            cout<<"The queue is empty\n";
            return;
        }

        cout<<"Queue: ";
        for(int i=front;;i=(i+1)%SIZE){
            cout<<queue[i]<<" ";
            if(i==rear){
                break;
            }
        }
        cout<<endl;
    }

    // Move the next student to the rear after their turn
    void RotateTurn(){
        if(IsEmpty()){
            cout<<"Cannot rotate, Queue is empty.\n";
            return;
        }

        int student = queue[front];
        Dequeue();
        Enqueue(student);
        cout<<"Student served: "<<student<<endl;
        Display();
    }
};

int main(){
    CircularQueue students;

    // Add students waiting for the shared computer
    students.Enqueue(101);
    students.Enqueue(102);
    students.Enqueue(103);

    // Run five turns
    for(int turn=1;turn<=5;turn++){
        cout<<"Turn "<<turn<<endl;
        students.RotateTurn();
    }

    // Test rotating an empty queue
    CircularQueue emptyQueue;
    emptyQueue.RotateTurn();

    // Test rotating a queue with one student
    CircularQueue oneStudent;
    oneStudent.Enqueue(201);
    oneStudent.RotateTurn();

    return 0;
}
