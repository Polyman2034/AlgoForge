
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    Node(int value) {
        data = value;
        next = prev = NULL;
    }
};

class Deque {
    Node *front, *rear;

public:
    Deque() {
        front = rear = NULL;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void insertFront(int value) {
        Node *newNode = new Node(value);

        if (isEmpty()) {
            front = rear = newNode;
        }
        else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }

        cout << "Customer added at front\n";
    }

    void insertRear(int value) {
        Node *newNode = new Node(value);

        if (isEmpty()) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }

        cout << "Customer added at rear\n";
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return;
        }

        Node *temp = front;

        cout << "Customer removed: "
             << temp->data << endl;

        front = front->next;

        if (front == NULL)
            rear = NULL;
        else
            front->prev = NULL;

        delete temp;
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return;
        }

        Node *temp = rear;

        cout << "Customer removed: "
             << temp->data << endl;

        rear = rear->prev;

        if (rear == NULL)
            front = NULL;
        else
            rear->next = NULL;

        delete temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return;
        }

        Node *temp = front;

        cout << "Customers: ";

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    ~Deque() {
        while (front != NULL) {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
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

