
#include <iostream>
using namespace std;

#define MAX 5

class Deque {
    int arr[MAX];
    int front, rear;

public:
    Deque() {
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (front == 0 && rear == MAX - 1) ||
               (front == rear + 1);
    }

    void insertFront(int value) {
        if (isFull()) {
            cout << "Deque is Full\n";
            return;
        }

        if (isEmpty())
            front = rear = 0;
        else
            front = (front - 1 + MAX) % MAX;

        arr[front] = value;

        cout << "Customer added at front\n";
    }

    void insertRear(int value) {
        if (isFull()) {
            cout << "Deque is Full\n";
            return;
        }

        if (isEmpty())
            front = rear = 0;
        else
            rear = (rear + 1) % MAX;

        arr[rear] = value;

        cout << "Customer added at rear\n";
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return;
        }

        cout << "Customer removed: " << arr[front] << endl;

        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % MAX;
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return;
        }

        cout << "Customer removed: " << arr[rear] << endl;

        if (front == rear)
            front = rear = -1;
        else
            rear = (rear - 1 + MAX) % MAX;
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return;
        }

        cout << "Customers: ";

        int i = front;

        while (true) {
            cout << arr[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % MAX;
        }

        cout << endl;
    }
};

int main() {
    Deque dq;
    int type, choice, value;

    cout << "\nSHOPPING MALL DEQUE";
    cout << "\n1. Input Restricted Deque";
    cout << "\n2. Output Restricted Deque";
    cout << "\nEnter Deque Type: ";
    cin >> type;

    do {
        cout << "\n1. Insert at Front";
        cout << "\n2. Insert at Rear";
        cout << "\n3. Delete from Front";
        cout << "\n4. Delete from Rear";
        cout << "\n5. Display";
        cout << "\n6. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                if (type == 1) {
                    cout << "Insertion allowed only at rear\n";
                }
                else {
                    cout << "Enter Customer ID: ";
                    cin >> value;
                    dq.insertFront(value);
                }
                break;

            case 2:
                cout << "Enter Customer ID: ";
                cin >> value;
                dq.insertRear(value);
                break;

            case 3:
                dq.deleteFront();
                break;

            case 4:
                if (type == 1) {
                    dq.deleteRear();
                }
                else {
                    cout << "Deletion allowed only from front\n";
                }
                break;

            case 5:
                dq.display();
                break;

            case 6:
                cout << "Thank You\n";
                break;

            default:
                cout << "Invalid Choice\n";
        }

    } while (choice != 6);

    return 0;
}
