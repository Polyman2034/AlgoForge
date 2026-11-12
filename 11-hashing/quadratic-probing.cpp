
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value);
};

Node::Node(int value)
{
    data = value;
    next = NULL;
}

class HashTable
{
    Node* table[20];

public:
    HashTable();
    void insert(int key);
    void display();
    ~HashTable();
};

HashTable::HashTable()
{
    for (int i = 0; i < 20; i++)
        table[i] = NULL;
}

void HashTable::insert(int key)
{
    int index = key % 20;

    Node* newNode = new Node(key);

    if (table[index] == NULL)
    {
        table[index] = newNode;
    }
    else
    {
        Node* temp = table[index];

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }
}

void HashTable::display()
{
    cout << "\nHash Table using Separate Chaining:\n";

    for (int i = 0; i < 20; i++)
    {
        cout << i << " --> ";

        Node* temp = table[i];

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
}

HashTable::~HashTable()
{
    for (int i = 0; i < 20; i++)
    {
        Node* temp = table[i];

        while (temp != NULL)
        {
            Node* del = temp;
            temp = temp->next;
            delete del;
        }
    }
}

int main()
{
    HashTable h;

    int arr[20] = {
        33, 56, 78, 12, 10,
        67, 89, 99, 100, 23,
        45, 71, 39, 62, 59,
        90, 91, 20, 75, 66
    };

    for (int i = 0; i < 20; i++)
    {
        h.insert(arr[i]);
    }

    h.display();

    return 0;
}

