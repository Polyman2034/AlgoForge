#include <iostream>
using namespace std;


// NODE CLASS

class Node
{
public:
    int marks;
    Node *prev;
    Node *next;
};


// LIST CLASS

class List
{
    Node *listptr, *temp;

public:

    List()
    {
        listptr = NULL;
        temp = NULL;
    }

    // BASIC FUNCTIONS
    void create();
    void display();

    // SORTING
    void sort();

    // MERGING
    void merge(List l2);
};


// CREATE

void List::create()
{
    int n;

    cout << "\nEnter number of nodes: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        Node *newnode = new Node;

        cout << "\nEnter Marks: ";
        cin >> newnode->marks;

        newnode->prev = NULL;
        newnode->next = NULL;

        if (listptr == NULL)
        {
            listptr = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;

            temp = newnode;
        }
    }
}


// DISPLAY

void List::display()
{
    if (listptr == NULL)
    {
        cout << "\nList is empty.";
        return;
    }

    temp = listptr;

    while (temp != NULL)
    {
        cout << temp->marks << "\t";
        temp = temp->next;
    }

    cout << endl;
}


// SORT

void List::sort()
{
    Node *p, *q;

    for (p = listptr; p != NULL; p = p->next)
    {
        for (q = p->next; q != NULL; q = q->next)
        {
            if (p->marks > q->marks)
            {
                swap(p->marks, q->marks);
            }
        }
    }

    cout << "\nList sorted.";
}


// MERGE

void List::merge(List l2)
{
    Node *p = listptr;
    Node *q = l2.listptr;

    List l3;

    while (p != NULL && q != NULL)
    {
        Node *newnode = new Node;

        if (p->marks <= q->marks)
        {
            newnode->marks = p->marks;
            p = p->next;
        }
        else
        {
            newnode->marks = q->marks;
            q = q->next;
        }

        newnode->prev = NULL;
        newnode->next = NULL;

        if (l3.listptr == NULL)
        {
            l3.listptr = newnode;
            l3.temp = newnode;
        }
        else
        {
            l3.temp->next = newnode;
            newnode->prev = l3.temp;

            l3.temp = newnode;
        }
    }


    // REMAINING NODES OF FIRST LIST

    while (p != NULL)
    {
        Node *newnode = new Node;

        newnode->marks = p->marks;
        newnode->prev = NULL;
        newnode->next = NULL;

        l3.temp->next = newnode;
        newnode->prev = l3.temp;

        l3.temp = newnode;

        p = p->next;
    }


    // REMAINING NODES OF SECOND LIST

    while (q != NULL)
    {
        Node *newnode = new Node;

        newnode->marks = q->marks;
        newnode->prev = NULL;
        newnode->next = NULL;

        l3.temp->next = newnode;
        newnode->prev = l3.temp;

        l3.temp = newnode;

        q = q->next;
    }


    cout << "\nMerged Sorted List: ";
    l3.display();
}


// MAIN

int main()
{
    List l1, l2;

    cout << "\nFIRST LIST";
    l1.create();

    cout << "\nSECOND LIST";
    l2.create();


    cout << "\n\nFirst List: ";
    l1.display();

    cout << "\nSecond List: ";
    l2.display();


    // SORT BOTH LISTS

    cout << "\n\nSorting First List...";
    l1.sort();

    cout << "\nSorting Second List...";
    l2.sort();


    cout << "\n\nSorted First List: ";
    l1.display();

    cout << "\nSorted Second List: ";
    l2.display();


    // MERGE

    l1.merge(l2);


    return 0;
}
