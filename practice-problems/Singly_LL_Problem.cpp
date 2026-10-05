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
    }

    // Create Node
    void create();

    // Inserting the Node
    void insertBeginning();
    void insertEnd();
    void insertPosition();

    // Deleting the Node
    void deleteBeginning();
    void deleteEnd();
    void deletePosition();

    // Display the Linked List
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

    exist = true;
}


void ll::insertBeginning()
{

    
}


void ll::insertEnd()
{
    
}


void ll::insertPosition()
{

    
}


void ll::deleteBeginning()
{
    
}


void ll::deleteEnd()
{
    
}


void ll::deletePosition()
{
    
}


void ll::display()
{
    if(!exist || head == NULL)
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
