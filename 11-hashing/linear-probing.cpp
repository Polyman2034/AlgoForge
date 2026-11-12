
#include <iostream>
using namespace std;

class HashTable
{
    int table[6];

public:
    HashTable();
    void insert(int key);
    void display();
};

HashTable::HashTable()
{
    for (int i = 0; i < 6; i++)
        table[i] = -1;
}

void HashTable::insert(int key)
{
    int index = key % 6;
    int start = index;

    while (table[index] != -1)
    {
        index = (index + 1) % 6;

        if (index == start)
        {
            cout << "Hash Table is Full!" << endl;
            return;
        }
    }

    table[index] = key;
}

void HashTable::display()
{
    cout << "\nHash Table:\n";

    for (int i = 0; i < 6; i++)
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
    int n, key;

    cout << "Enter number of flavours: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter flavour code: ";
        cin >> key;

        h.insert(key);
    }

    h.display();

    return 0;
}

