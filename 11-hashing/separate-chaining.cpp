
#include <iostream>
using namespace std;

class HashTable
{
    int table[11];

public:
    HashTable();
    void insert(int key);
    void display();
};

HashTable::HashTable()
{
    for (int i = 0; i < 11; i++)
        table[i] = -1;
}

void HashTable::insert(int key)
{
    int index;
    int i;

    for (i = 0; i < 11; i++)
    {
        index = (key % 11 + i * i) % 11;

        if (table[index] == -1)
        {
            table[index] = key;
            return;
        }
    }

    cout << "Cannot insert " << key << endl;
}

void HashTable::display()
{
    cout << "\nHash Table using Quadratic Probing:\n";

    for (int i = 0; i < 11; i++)
    {
        cout << i << " --> ";

        if (table[i] == -1)
            cout << "Empty";
        else
            cout << table[i];

        cout << endl;
    }
}

int main()
{
    HashTable h;

    int arr[11] = {
        25, 15, 10, 5, 11,
        19, 16, 36, 42, 28, 32
    };

    for (int i = 0; i < 11; i++)
    {
        h.insert(arr[i]);
    }

    h.display();

    return 0;
}

