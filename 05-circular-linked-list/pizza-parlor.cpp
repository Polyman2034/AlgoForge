#include <iostream>
using namespace std;


// NODE CLASS
class Node
{
public:
    int order;
    Node* next;
};

// LIST CLASS
class List
{
    Node *head, *temp;
    int count;
    int maxOrders;

public:

    // Constructor
    List(int M)
    {
        head = NULL;
        temp = NULL;
        count = 0;
        maxOrders = M;
    }

    // Function Declaration
    void create(int order);
    void insert(int order);
    void deleteOrder();
    void display();
};

// CREATE FUNCTION
void List::create(int order)
{
    Node* newnode = new Node;

    newnode->order = order;

    if (head == NULL)
    {
        head = newnode;
        temp = newnode;

        newnode->next = head;
    }
    else
    {
        temp->next = newnode;
        temp = newnode;

        temp->next = head;
    }
}

// INSERT FUNCTION
void List::insert(int order)
{
    if (count >= maxOrders)
    {
        cout << "Pizza parlor is full!\n";
        return;
    }

    create(order);
    count++;

    cout << "Order " << order << " placed successfully.\n";
}

// DELETE FUNCTION
void List::deleteOrder()
{
    if (head == NULL)
    {
        cout << "No orders to serve.\n";
        return;
    }

    Node* del = head;

    cout << "Order " << head->order << " served.\n";

    if (head == temp)
    {
        head = NULL;
        temp = NULL;
    }
    else
    {
        head = head->next;
        temp->next = head;
    }

    delete del;
    count--;
}

// DISPLAY FUNCTION
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

    cout << "Enter maximum number of orders: ";
    cin >> M;

    List pizza(M);

    do
    {
        cout << "\n----- PIZZA PARLOR -----\n";
        cout << "1. Place Order\n";
        cout << "2. Serve Order\n";
        cout << "3. Display Orders\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            pizza.insert(orderNo);
            orderNo++;
            break;

        case 2:
            pizza.deleteOrder();
            break;

        case 3:
            pizza.display();
            break;

        case 4:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
