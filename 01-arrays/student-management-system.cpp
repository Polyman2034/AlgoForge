#include <iostream>
using namespace std;

class stud
{
public:
    long long prn;
    char name[50];
    long long mobile;
    char address[200];

    void getdata();
    void putdata();
    void update();
};

// GET DATA function

void stud::getdata()
{
    cout << "Enter PRN: ";
    cin >> prn;

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Mobile: ";
    cin >> mobile;

    cout << "Enter Address: ";
    cin >> address;
}

// PUT DATA function

void stud::putdata()
{
    cout << "PRN: " << prn << endl;
    cout << "Name: " << name << endl;
    cout << "Mobile: " << mobile << endl;
    cout << "Address: " << address << endl;
}

// UPDATE function

void stud::update()
{
    int ch;

    cout << "\nWhat do you want to update?" << endl;
    cout << "1. Update PRN" << endl;
    cout << "2. Update Name" << endl;
    cout << "3. Update Mobile" << endl;
    cout << "4. Update Address" << endl;

    cout << "Enter choice: ";
    cin >> ch;

    switch (ch)
    {
    case 1:
        cout << "Enter New PRN: ";
        cin >> prn;
        cout << "PRN Updated Successfully." << endl;
        break;

    case 2:
        cout << "Enter New Name: ";
        cin >> name;
        cout << "Name Updated Successfully." << endl;
        break;

    case 3:
        cout << "Enter New Mobile: ";
        cin >> mobile;
        cout << "Mobile Updated Successfully." << endl;
        break;

    case 4:
        cout << "Enter New Address: ";
        cin >> address;
        cout << "Address Updated Successfully." << endl;
        break;

    default:
        cout << "Invalid choice." << endl;
    }
}

// MAIN FUNCTION

int main()
{
    stud s[5];

    int n = 0;
    int choice;
    char p;

    do
    {
        cout << "\nSTUDENT MANAGEMENT SYSTEM" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display Students" << endl;
        cout << "3. Update Student" << endl;
        cout << "4. Delete Student" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        //ADD

        case 1:

            if (n < 5)
            {
                s[n].getdata();
                n++;
            }
            else
            {
                cout << "Student storage is full!" << endl;
            }

            break;


        //DISPLAY

        case 2:

            if (n == 0)
            {
                cout << "No students available." << endl;
            }

            for (int i = 0; i < n; i++)
            {
                cout << "\nStudent " << i + 1 << endl;
                cout << "------------------" << endl;

                s[i].putdata();
            }

            break;


        //UPDATE

        case 3:
        {
            long long searchPRN;
            bool found = false;

            cout << "Enter PRN of student: ";
            cin >> searchPRN;

            for (int i = 0; i < n; i++)
            {
                if (s[i].prn == searchPRN)
                {
                    s[i].update();
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Student not found." << endl;
            }

            break;
        }


        //DELETE

        case 4:
        {
            long long searchPRN;
            int pos = -1;

            cout << "Enter PRN of student to delete: ";
            cin >> searchPRN;

            // Find the position of student

            for (int i = 0; i < n; i++)
            {
                if (s[i].prn == searchPRN)
                {
                    pos = i;
                    break;
                }
            }

            // Student found

            if (pos != -1)
            {
                // Shift all students one position to the left

                for (int i = pos; i < n - 1; i++)
                {
                    s[i] = s[i + 1];
                }

                // Reduce number of students

                n--;

                cout << "Student deleted successfully." << endl;
            }
            else
            {
                cout << "Student not found." << endl;
            }

            break;
        }


        default:
            cout << "Invalid choice." << endl;
        }

        cout << "\nDo you want to continue? (y/n): ";
        cin >> p;

    } while (p == 'Y' || p == 'y');

    return 0;
}
