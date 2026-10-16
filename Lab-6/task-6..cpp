/*  Muhammad Saad
    548277
    BSCS-15D
    16/10/2026*/
#include <iostream>
using namespace std;

class Queue {
private:
    static const int SIZE = 5;
    int customers[SIZE];
    int front;
    int rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    bool isFull() {
        return rear == SIZE - 1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full.\n";
            return;
        }

        if (isEmpty()) {
            front = 0;
        }

        rear++;
        customers[rear] = value;
        cout << "Customer " << value << " added to queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Served customer: " << customers[front] << endl;

        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }

    int peekFront() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return -1;
        }
        return customers[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << customers[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue queue;
    int choice;
    int token;

    do {
        cout << "\nCustomer Service Queue\n";
        cout << "1. Add customer\n";
        cout << "2. Serve next\n";
        cout << "3. View next\n";
        cout << "4. Display queue\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter customer token number: ";
            cin >> token;
            queue.enqueue(token);
            break;

        case 2:
            queue.dequeue();
            break;

        case 3:
            if (queue.peekFront() != -1) {
                cout << "Next customer token: " << queue.peekFront() << endl;
            }
            break;

        case 4:
            queue.display();
            break;

        case 5:
            cout << "Exiting the customer service queue.\n";
            break;

        default:
            cout << "Invalid menu choice. Please choose a number from 1 to 5.\n";
            break;
        }
    } while (choice != 5);

    return 0;
}
