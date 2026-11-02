#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class sose
{
    struct Student
    {
        int roll;
        string name;
        float sgpa;
        string dept;
    };

    Student s[15] = {
        {5, "Rahul", 8.2, "Computer"},
        {2, "Amit", 9.1, "IT"},
        {9, "Sneha", 8.8, "Computer"},
        {1, "Priya", 9.5, "Computer"},
        {7, "Rohan", 7.9, "Mechanical"},
        {4, "Neha", 8.8, "Computer"},
        {12, "Akash", 9.2, "IT"},
        {3, "Pooja", 8.5, "Computer"},
        {10, "Kiran", 7.5, "Civil"},
        {6, "Vikas", 8.9, "Computer"},
        {15, "Anjali", 9.5, "IT"},
        {8, "Sagar", 7.8, "Mechanical"},
        {11, "Meena", 8.3, "Computer"},
        {13, "Riya", 9.0, "IT"},
        {14, "Nikhil", 8.6, "Computer"}
    };

public:

    void display();

    void BubbleSort();
    void InsertionSort();
    void QuickSort();
    void LinearSearch();
    void BinarySearch();
    void FibonacciSearch();

    void quickSort(int low, int high);
};


// ================= DISPLAY =================

void sose::display()
{
    for(int i = 0; i < 15; i++)
    {
        cout << s[i].roll << " "
             << s[i].name << " "
             << s[i].sgpa << " "
             << s[i].dept << endl;
    }
}


// ================= A) BUBBLE SORT =================

void sose::BubbleSort()
{
    for(int i = 0; i < 14; i++)
    {
        for(int j = 0; j < 14-i; j++)
        {
            if(s[j].roll > s[j+1].roll)
            {
                swap(s[j], s[j+1]);
            }
        }
    }

    cout << "\nStudents according to Roll Number:\n";
    display();
}


// ================= B) INSERTION SORT =================

void sose::InsertionSort()
{
    for(int i = 1; i < 15; i++)
    {
        Student key = s[i];

        int j = i - 1;

        while(j >= 0 && s[j].name > key.name)
        {
            s[j+1] = s[j];
            j--;
        }

        s[j+1] = key;
    }

    cout << "\nStudents in Alphabetical Order:\n";
    display();
}


// ================= C) QUICK SORT =================

void sose::quickSort(int low, int high)
{
    if(low >= high)
        return;

    float pivot = s[high].sgpa;

    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(s[j].sgpa > pivot)
        {
            i++;
            swap(s[i], s[j]);
        }
    }

    swap(s[i+1], s[high]);

    int p = i + 1;

    quickSort(low, p-1);
    quickSort(p+1, high);
}


void sose::QuickSort()
{
    quickSort(0, 14);

    cout << "\nTop 10 Toppers:\n";

    for(int i = 0; i < 10; i++)
    {
        cout << s[i].roll << " "
             << s[i].name << " "
             << s[i].sgpa << " "
             << s[i].dept << endl;
    }
}


// ================= D) LINEAR SEARCH =================

void sose::LinearSearch()
{
    float key;

    cout << "\nEnter SGPA: ";
    cin >> key;

    bool found = false;

    for(int i = 0; i < 15; i++)
    {
        if(s[i].sgpa == key)
        {
            cout << s[i].roll << " "
                 << s[i].name << " "
                 << s[i].sgpa << " "
                 << s[i].dept << endl;

            found = true;
        }
    }

    if(!found)
        cout << "Student not found.\n";
}


// ================= E) BINARY SEARCH =================

void sose::BinarySearch()
{
    // First sort according to name
    InsertionSort();

    string key;

    cout << "\nEnter student name: ";
    cin >> key;

    int low = 0;
    int high = 14;

    int found = -1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(s[mid].name == key)
        {
            found = mid;
            break;
        }
        else if(s[mid].name < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if(found == -1)
    {
        cout << "Student not found.\n";
    }
    else
    {
        cout << "\nStudent Found:\n";

        cout << s[found].roll << " "
             << s[found].name << " "
             << s[found].sgpa << " "
             << s[found].dept << endl;
    }
}


// ================= F) FIBONACCI SEARCH =================

void sose::FibonacciSearch()
{
    // Sort according to department

    for(int i = 1; i < 15; i++)
    {
        Student key = s[i];

        int j = i - 1;

        while(j >= 0 && s[j].dept > key.dept)
        {
            s[j+1] = s[j];
            j--;
        }

        s[j+1] = key;
    }

    string key;

    cout << "\nEnter department: ";
    cin >> key;

    int fib2 = 0;
    int fib1 = 1;
    int fib = fib1 + fib2;

    while(fib < 15)
    {
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }

    int offset = -1;

    while(fib > 1)
    {
        int i = min(offset + fib2, 14);

        if(s[i].dept < key)
        {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;

            offset = i;
        }
        else if(s[i].dept > key)
        {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
        else
        {
            cout << "\nDepartment Found: " << key << endl;

            for(int j = 0; j < 15; j++)
            {
                if(s[j].dept == key)
                {
                    cout << s[j].roll << " "
                         << s[j].name << " "
                         << s[j].sgpa << " "
                         << s[j].dept << endl;
                }
            }

            return;
        }
    }

    cout << "\nDepartment not found.\n";
}


// ================= MAIN =================

int main()
{
    sose obj;

    int choice;

    do
    {
        cout << "\n===== STUDENT DATABASE =====\n";

        cout << "1. Bubble Sort - Roll Number\n";
        cout << "2. Insertion Sort - Name\n";
        cout << "3. Quick Sort - Top 10\n";
        cout << "4. Linear Search - SGPA\n";
        cout << "5. Binary Search - Name\n";
        cout << "6. Fibonacci Search - Department\n";
        cout << "0. Exit\n";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                obj.BubbleSort();
                break;

            case 2:
                obj.InsertionSort();
                break;

            case 3:
                obj.QuickSort();
                break;

            case 4:
                obj.LinearSearch();
                break;

            case 5:
                obj.BinarySearch();
                break;

            case 6:
                obj.FibonacciSearch();
                break;

            case 0:
                cout << "Program ended.";
                break;

            default:
                cout << "Invalid choice.";
        }

    } while(choice != 0);

    return 0;
}
