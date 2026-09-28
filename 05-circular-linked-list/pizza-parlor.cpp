/*Pizza parlor accepting maximum M orders. Orders are served in first come first served basis. Order
once placed cannot be cancelled. Write a program to simulate the system using circular linked list.
    */
#include <iostream>
using namespace std;

// NODE CLASS
class Node
{
public:
    int order;
    Node* next;

    Node(int order)
    {
        this->order = order;
        next = NULL;
    }
};

// LIST CLASS
class List
{
    Node* head;
    Node* tail;
    int count;
    int maxOrders;

public:

    List(int M)
    {
        head = NULL;
        tail = NULL;
        count = 0;
        maxOrders = M;
    }

    void insert(int order);
    void deleteOrder();
    void display();
};

// INSERT ORDER
void List::insert(int order)
{
    if (count == maxOrders)
    {
        cout << "Pizza parlor is full!\n";
        return;
    }

    Node* newNode = new Node(order);

    if (head == NULL)
    {
        head = tail = newNode;
        tail->next = head;
    }
    else
    {
        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
    }

    count++;

    cout << "Order " << order << " placed successfully.\n";
}

// SERVE ORDER
void List::deleteOrder()
{
    if (head == NULL)
    {
        cout << "No orders to serve.\n";
        return;
    }

    Node* del = head;

    cout << "Order " << head->order << " served.\n";

    if (head == tail)
    {
        head = tail = NULL;
    }
    else
    {
        head = head->next;
        tail->next = head;
    }

    delete del;
    count--;
}

// DISPLAY ORDERS
void List::display()
{
    if (head == NULL)
    {
        cout << "No pending orders.\n";
        return;
    }

    Node* current = head;

    cout << "Pending Orders: ";

    do
    {
        cout << current->order << " ";
        current = current->next;
    }
    while (current != head);

    cout << endl;
}

// MAIN FUNCTION
int main()
{
    int M;
    int choice;
    int orderNo = 1;
    char again;

    cout << "Enter maximum number of orders: ";
    cin >> M;

    List pizza(M);

    do
    {
        cout << "\n----- PIZZA PARLOR -----\n";
        cout << "1. Place Order\n";
        cout << "2. Serve Order\n";
        cout << "3. Display Orders\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            pizza.insert(orderNo++);
            break;

        case 2:
            pizza.deleteOrder();
            break;

        case 3:
            pizza.display();
            break;

        default:
            cout << "Invalid choice!\n";
        }

        cout << "\nDo you want to continue? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    cout << "\nProgram ended.\n";

    return 0;
}
