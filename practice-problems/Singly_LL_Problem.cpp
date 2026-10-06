#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class ll
{
    Node *head;

public:
    int n;
    bool exist = false;

    ll()
    {
        head = NULL;
        n = 0;
    }

    void create();
    void insertBeginning();
    void insertEnd();
    void insertPosition();
    void deleteBeginning();
    void deleteEnd();
    void deletePosition();
    void display();
};

void ll::create()
{
    int marks;

    cout << "Enter the number of Nodes: ";
    cin >> n;

    head = NULL;

    Node *previous = NULL;

    for(int i = 1; i <= n; i++)
    {
        Node *newNode = new Node;

        cout << "Enter the Marks: ";
        cin >> marks;

        newNode->data = marks;
        newNode->next = NULL;

        if(i == 1)
        {
            head = newNode;
        }
        else
        {
            previous->next = newNode;
        }

        previous = newNode;
    }

    if(n > 0)
        exist = true;
    else
        exist = false;
}

void ll::insertBeginning()
{
    int marks;

    Node *newNode = new Node;

    cout << "Enter the Marks: ";
    cin >> marks;

    newNode->data = marks;

    newNode->next = head;

    head = newNode;

    n++;
    exist = true;
}

void ll::insertEnd()
{
    int marks;

    Node *newNode = new Node;

    cout << "Enter the Marks: ";
    cin >> marks;

    newNode->data = marks;
    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    n++;
    exist = true;
}

void ll::insertPosition()
{
    int marks, pn;

    cout << "Enter the Position: ";
    cin >> pn;

    if(pn == 1)
    {
        insertBeginning();
        return;
    }

    if(head == NULL || pn < 1 || pn > n + 1)
    {
        cout << "Invalid position!" << endl;
        return;
    }

    Node *newNode = new Node;

    cout << "Enter the Marks: ";
    cin >> marks;

    newNode->data = marks;

    Node *temp = head;

    for(int pos = 1; pos < pn - 1; pos++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    n++;
    exist = true;
}

void ll::deleteBeginning()
{
    if(head == NULL)
    {
        cout << "Linked List is empty!" << endl;
        return;
    }

    Node *temp = head;

    head = head->next;

    delete temp;

    n--;

    if(n == 0)
        exist = false;
}

void ll::deleteEnd()
{
    if(head == NULL)
    {
        cout << "Linked List is empty!" << endl;
        return;
    }

    // Only one node
    if(head->next == NULL)
    {
        delete head;

        head = NULL;

        n--;
        exist = false;

        return;
    }

    Node *temp = head;

    // Reach second-last node
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;

    temp->next = NULL;

    n--;
}

void ll::deletePosition()
{
    int pn;

    cout << "Enter the Position: ";
    cin >> pn;

    if(head == NULL || pn < 1 || pn > n)
    {
        cout << "Invalid position!" << endl;
        return;
    }

    if(pn == 1)
    {
        deleteBeginning();
        return;
    }

    Node *temp = head;

    // Reach node before position
    for(int pos = 1; pos < pn - 1; pos++)
    {
        temp = temp->next;
    }

    Node *deleteNode = temp->next;

    temp->next = deleteNode->next;

    delete deleteNode;

    n--;

    if(n == 0)
        exist = false;
}

void ll::display()
{
    if(head == NULL)
    {
        cout << "Linked List is empty!" << endl;
        return;
    }

    Node *temp = head;

    cout << "Linked List: ";

    while(temp != NULL)
    {
        cout << temp->data << " ";

        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    ll list;

    int choice;

    do
    {
        cout << "\n========== LINKED LIST ==========\n";
        cout << "1. Create Linked List\n";
        cout << "2. Insert at Beginning\n";
        cout << "3. Insert at End\n";
        cout << "4. Insert at Position\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete from Position\n";
        cout << "8. Display Linked List\n";
        cout << "0. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                list.create();
                break;

            case 2:
                list.insertBeginning();
                break;

            case 3:
                list.insertEnd();
                break;

            case 4:
                list.insertPosition();
                break;

            case 5:
                list.deleteBeginning();
                break;

            case 6:
                list.deleteEnd();
                break;

            case 7:
                list.deletePosition();
                break;

            case 8:
                list.display();
                break;

            case 0:
                cout << "\nExiting...";
                break;

            default:
                cout << "\nInvalid choice!";
        }

    } while(choice != 0);

    return 0;
}
