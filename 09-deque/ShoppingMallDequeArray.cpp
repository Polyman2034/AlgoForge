#include <iostream>
using namespace std;

#define MAX 5

class InputRestrictedDeque {
private:
    int deque[MAX];
    int front, rear;

public:

    InputRestrictedDeque() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (front == 0 && rear == MAX - 1) ||
               (front == rear + 1);
    }

    // Insertion allowed only at rear
    void insertRear(int value) {

        if (isFull()) {
            cout << "Deque is Full\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % MAX;
        }

        deque[rear] = value;

        cout << value << " inserted at rear.\n";
    }

    // Deletion from front
    void deleteFront() {

        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return;
        }

        cout << deque[front] << " deleted from front.\n";

        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % MAX;
        }
    }

    // Deletion from rear
    void deleteRear() {

        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return;
        }

        cout << deque[rear] << " deleted from rear.\n";

        if (front == rear) {
            front = rear = -1;
        }
        else {
            rear = (rear - 1 + MAX) % MAX;
        }
    }

    void display() {

        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return;
        }

        cout << "Deque: ";

        int i = front;

        while (true) {
            cout << deque[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % MAX;
        }

        cout << endl;
    }
};

int main() {

    InputRestrictedDeque dq;

    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertRear(30);

    dq.display();

    dq.deleteFront();
    dq.display();

    dq.deleteRear();
    dq.display();

    return 0;
}
