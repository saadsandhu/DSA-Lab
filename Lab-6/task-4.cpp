/*  Muhammad Saad
    548277
    BSCS-15D
    16/10/2026*/
#include<iostream>
using namespace std;

class Queue{
private:
    static const int SIZE = 5;
    int items[SIZE];
    int front;
    int rear;

public:
    Queue(){
        front = -1;
        rear = -1;
    }

    bool isEmpty(){
        return rear == -1;
    }
    bool isFull(){
        return rear == SIZE-1;
    }

    // Funtion to push value
    void enqueue(int value){
       if(isFull()){
        cout<<"Queue is full\n";
        return;
       }
       if(isEmpty()){
        front = 0;
       }

    rear++;
    items[rear] = value;
    }



    void display(){
        if(isEmpty()){
            cout<<"The queue is empty\n"<<endl;
            return;
        }

        cout<<"Queue: ";
        for(int i=front;i<=rear;i++){
            cout<<items[i]<<" ";
        }
        cout<<endl;
    }
};

void main(){
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.display();
    queue.enqueue(40);
    queue.enqueue(50);
    queue.enqueue(60);
}
