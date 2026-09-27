#include <iostream>
using namespace std;

// Main class
class Array
{
public:

    // Data
    int n;
    int arr[100];
    bool exist = false;

    // Functions
    void read();
    void display();
    void calculate();
    void insert_pos();
    void delete_pos();
};


// Read array
void Array::read()
{
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements of array:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    exist = true;
}


// Display array
void Array::display()
{
    if (exist)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
}


// Calculate sum and average
void Array::calculate()
{
    int sum = 0;
    float avg;

    if (exist)
    {
        // Calculate sum
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }

        // Calculate average
        avg = static_cast<float>(sum) / n;

        cout << "Sum     : " << sum << endl;
        cout << "Average : " << avg << endl;
    }
}


// Insert at position
void Array::insert_pos()
{
    if (exist)
    {
        int pos;
        int new_element;

        cout << "At which position do you want to insert? ";
        cin >> pos;

        cout << "Which element do you want to insert? ";
        cin >> new_element;

        // Shift elements right
        for (int i = n; i > pos; i--)
        {
            arr[i] = arr[i - 1];
        }

        arr[pos] = new_element;
        n++;
    }
}


// Delete at position
void Array::delete_pos()
{
    if (exist)
    {
        int pos;

        cout << "At which position do you want to delete? ";
        cin >> pos;

        // Shift elements left
        for (int i = pos; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        n--;
    }
}


// Main function
int main()
{
    // Create object
    Array obj;

    // Read array
    obj.read();

    // Insert element
    obj.insert_pos();

    // Display array
    obj.display();

    // Delete element
    obj.delete_pos();

    // Display array
    obj.display();

    // Calculate result
    obj.calculate();

    return 0;
}
