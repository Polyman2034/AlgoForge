/*Design and develop program for insertion, updating, searching, sorting, listing and deletion operations
using singly linked list for any one of the following applications :-
"Placement Information System"*/
#include <iostream>
#include <string>
using namespace std;


// NODE CLASS

class Node
{
public:
    int id;
    string name;
    int prn;
    float cgpa;
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
    //BASIC FUNCTIONS
    void create();
    void display();
    void search();
    
    //INSERT FUNCTION
    void insert_start();
    void insert_end();
    void insert_position();
    void insert_after();
    
    //DELETE FUNCTION
    void delete_first();
    void delete_last();
    void delete_position();
    void delete_value();
    
    //UPDATE 
    void update();
    
    //SORTING
    void sort();
    
    //REVERSE 
    void reverse();
};


// CREATE

void List::create()
{
    int n;
    cout << "\nEnter number of nodes: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        Node *newnode = new Node;    // CREATE NODE

        cout << "\nEnter Roll No.: ";
        cin >> newnode->id;

        cout << "Enter Name: ";
        cin >> newnode->name;

        cout << "Enter PRN: ";
        cin >> newnode->prn;

        cout << "Enter CGPA: ";
        cin >> newnode->cgpa;

        newnode->next = NULL;
        if (listptr == NULL)
        {
            listptr = newnode;
            temp = newnode;   //   temp= head
      }
        else
        {
            temp->next = newnode;
            temp = newnode;    //temp=temp->next
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

    cout << "\n\nRoll No.\tName\tPRN\tCGPA\n";
    cout << "----------------------------------------\n";

    while (temp != NULL)
    {
        cout << temp->id << "\t\t";
        cout << temp->name << "\t";
        cout << temp->prn << "\t";
        cout << temp->cgpa << endl;

        temp = temp->next;
    }
}


// SEARCH

void List::search()
{
    int id;
    bool found = false;

    cout << "\nEnter Roll No. to search: ";
    cin >> id;

    temp = listptr;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            cout << "\nRecord Found!";
            cout << "\nRoll No.: " << temp->id;
            cout << "\nName: " << temp->name;
            cout << "\nPRN: " << temp->prn;
            cout << "\nCGPA: " << temp->cgpa << endl;
            found = true;
            break;
        }

        temp = temp->next;
    }

    if (found == false)
        cout << "\nRecord not found.";
}


// INSERT AT START

void List::insert_start()
{
    Node *newnode = new Node;

    cout << "\nEnter Roll No.: ";
    cin >> newnode->id;

    cout << "Enter Name: ";
    cin >> newnode->name;

    cout << "Enter PRN: ";
    cin >> newnode->prn;

    cout << "Enter CGPA: ";
    cin >> newnode->cgpa;

    newnode->next = listptr;
    listptr = newnode;

    cout << "\nNode inserted at beginning.";
}


// INSERT AT END

void List::insert_end()
{
    Node *newnode = new Node;

    cout << "\nEnter Roll No.: ";
    cin >> newnode->id;

    cout << "Enter Name: ";
    cin >> newnode->name;

    cout << "Enter PRN: ";
    cin >> newnode->prn;

    cout << "Enter CGPA: ";
    cin >> newnode->cgpa;

    newnode->next = NULL;

    if (listptr == NULL)
    {
        listptr = newnode;
    }
    else
    {
        temp = listptr;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }

    cout << "\nNode inserted at end.";
}


// INSERT AT SPECIFIC POSITION

void List::insert_position()
{
    int position;

    cout << "\nEnter position: ";
    cin >> position;

    if (position == 1)
    {
        insert_start();
        return;
    }

    Node *newnode = new Node;

    cout << "Enter Roll No.: ";
    cin >> newnode->id;

    cout << "Enter Name: ";
    cin >> newnode->name;

    cout << "Enter PRN: ";
    cin >> newnode->prn;

    cout << "Enter CGPA: ";
    cin >> newnode->cgpa;

    temp = listptr;

    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "\nInvalid position.";
        delete newnode;
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;

    cout << "\nNode inserted.";
}


// INSERT AFTER SPECIFIC ROLL NO.

void List::insert_after()
{
    int id;

    cout << "\nEnter Roll No. after which node is to be inserted: ";
    cin >> id;

    temp = listptr;

    while (temp != NULL && temp->id != id)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "\nRoll No. not found.";
        return;
    }

    Node *newnode = new Node;

    cout << "Enter Roll No.: ";
    cin >> newnode->id;

    cout << "Enter Name: ";
    cin >> newnode->name;

    cout << "Enter PRN: ";
    cin >> newnode->prn;

    cout << "Enter CGPA: ";
    cin >> newnode->cgpa;

    newnode->next = temp->next;
    temp->next = newnode;

    cout << "\nNode inserted.";
}


// DELETE FIRST

void List::delete_first()
{
    if (listptr == NULL)
    {
        cout << "\nList is empty.";
        return;
    }

    temp = listptr;
    listptr = listptr->next;

    delete temp;

    cout << "\nFirst node deleted.";
}


// DELETE LAST

void List::delete_last()
{
    if (listptr == NULL)
    {
        cout << "\nList is empty.";
        return;
    }

    if (listptr->next == NULL)
    {
        delete listptr;
        listptr = NULL;
        cout << "\nLast node deleted.";
        return;
    }

    temp = listptr;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;

    cout << "\nLast node deleted.";
}


// DELETE AT SPECIFIC POSITION

void List::delete_position()
{
    int position;

    cout << "\nEnter position to delete: ";
    cin >> position;

    if (listptr == NULL)
    {
        cout << "\nList is empty.";
        return;
    }

    if (position == 1)
    {
        delete_first();
        return;
    }

    temp = listptr;

    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
    {
        cout << "\nInvalid position.";
        return;
    }

    Node *q = temp->next;

    temp->next = q->next;

    delete q;

    cout << "\nNode deleted.";
}


// DELETE BY ROLL NO.

void List::delete_value()
{
    int id;

    cout << "\nEnter Roll No. to delete: ";
    cin >> id;

    if (listptr == NULL)
    {
        cout << "\nList is empty.";
        return;
    }

    if (listptr->id == id)
    {
        delete_first();
        return;
    }

    temp = listptr;

    
	while (temp->next != NULL && temp->next->id != id)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        cout << "\nRoll No. not found.";
        return;
    }

    Node *q = temp->next;

    temp->next = q->next;

    delete q;

    cout << "\nNode deleted.";
}


// UPDATE

void List::update()
{
    int id, choice;

    cout << "\nEnter Roll No. to update: ";
    cin >> id;

    temp = listptr;

    while (temp != NULL && temp->id != id)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "\nRoll No. not found.";
        return;
    }

    cout << "\nRecord found.";

    do
    {
        cout << "\n\n1. Roll No.";
        cout << "\n2. Name";
        cout << "\n3. PRN";
        cout << "\n4. CGPA";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter new Roll No.: ";
            cin >> temp->id;
            break;

        case 2:
            cout << "Enter new Name: ";
            cin >> temp->name;
            break;

        case 3:
            cout << "Enter new PRN: ";
            cin >> temp->prn;
            break;

        case 4:
            cout << "Enter new CGPA: ";
            cin >> temp->cgpa;
            break;

        case 5:
            break;

        default:
            cout << "Invalid choice.";
        }

    } while (choice != 5);
}


// SORT

void List::sort()
{
    Node *p, *q;

    for (p = listptr; p != NULL; p = p->next)
    {
        for (q = p->next; q != NULL; q = q->next)
        {
            if (p->id > q->id)
            {
                swap(p->id, q->id);
                swap(p->name, q->name);
                swap(p->prn, q->prn);
                swap(p->cgpa, q->cgpa);
            }
        }
    }

    cout << "\nList sorted according to Roll No.";
}


// REVERSE

void List::reverse()
{
    Node *back = NULL;
    Node *curr = listptr;
    Node *forward;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = back;
        back = curr;
        curr = forward;
    }

    listptr = back;

    cout << "\nList reversed.";
}


// MAIN

int main()
{
    List l;
    int ch, p = 1;

    while (p == 1)
    {
        
        cout << "\n        SINGLY LINKED LIST";
       

        cout << "\n1.  Create";
        cout << "\n2.  Display";
        cout << "\n3.  Search";
        cout << "\n4.  Insert at Start";
        cout << "\n5.  Insert at End";
        cout << "\n6.  Insert at Position";
        cout << "\n7.  Insert After Specific Roll No.";
        cout << "\n8.  Delete First";
        cout << "\n9.  Delete Last";
        cout << "\n10. Delete at Position";
        cout << "\n11. Delete Specific Roll No.";
        cout << "\n12. Update";
        cout << "\n13. Sort";
        cout << "\n14. Reverse";
        cout << "\n\nEnter Choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            l.create();
            break;

        case 2:
            l.display();
            break;

        case 3:
            l.search();
            break;

        case 4:
            l.insert_start();
            break;

        case 5:
            l.insert_end();
            break;

        case 6:
            l.insert_position();
            break;

        case 7:
            l.insert_after();
            break;

        case 8:
            l.delete_first();
            break;

        case 9:
            l.delete_last();
            break;

        case 10:
            l.delete_position();
            break;

        case 11:
            l.delete_value();
            break;

        case 12:
            l.update();
            break;

        case 13:
            l.sort();
            break;

        case 14:
            l.reverse();
            break;

        default:
            cout << "\nInvalid Choice.";
        }

        cout << "\n\nPress 1 to continue: ";
        cin >> p;
    }

    return 0;
}
