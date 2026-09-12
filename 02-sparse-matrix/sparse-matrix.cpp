#include <iostream>
using namespace std;

// Define sparse matrix class
class matrix
{
public:

    // Store row, column and value
    int arr[10][3];

    // Store number of non-zero elements
    int n;

    // Declare matrix operations
    void getdata();
    void display();
    void add(matrix m1, matrix m2);
    void multiply(matrix m1, matrix m2);
    void transpose();
    void fastTranspose();
    void getTranspose(matrix m1, matrix m2);

    // Initialize matrix
    matrix()
    {
        n = 0;

        // Initialize array elements
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                arr[i][j] = 0;
            }
        }
    }
};


// Input sparse matrix data
void matrix::getdata()
{
    // Read number of non-zero elements
    cout << "Enter the total number of non-zero elements: ";
    cin >> n;

    // Validate number of elements
    if (n < 0 || n > 10)
    {
        cout << "Invalid number of elements. Maximum is 10.\n";
        n = 0;
        return;
    }

    // Read row, column and value
    cout << "Enter the elements (row column value):\n";

    // Store each non-zero element
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
}


// Display sparse matrix
void matrix::display()
{
    // Print table heading
    cout << "\nrows\tcolumn\tvalue\n";

    // Print all non-zero elements
    for (int i = 0; i < n; i++)
    {
        cout << arr[i][0] << "\t"
             << arr[i][1] << "\t"
             << arr[i][2] << "\n";
    }
}


// Add two sparse matrices
void matrix::add(matrix m1, matrix m2)
{
    // Initialize pointers for both matrices
    int i = 0, j = 0, k = 0;

    // Compare elements of both matrices
    while (i < m1.n && j < m2.n)
    {
        // Check same row and column
        if (m1.arr[i][0] == m2.arr[j][0] &&
            m1.arr[i][1] == m2.arr[j][1])
        {
            // Add matching values
            int sum = m1.arr[i][2] + m2.arr[j][2];

            // Store non-zero sum
            if (sum != 0)
            {
                arr[k][0] = m1.arr[i][0];
                arr[k][1] = m1.arr[i][1];
                arr[k][2] = sum;
                k++;
            }

            // Move both pointers
            i++;
            j++;
        }

        // Check Matrix 1 element comes first
        else if (m1.arr[i][0] < m2.arr[j][0] ||
                (m1.arr[i][0] == m2.arr[j][0] &&
                 m1.arr[i][1] < m2.arr[j][1]))
        {
            // Copy Matrix 1 element
            arr[k][0] = m1.arr[i][0];
            arr[k][1] = m1.arr[i][1];
            arr[k][2] = m1.arr[i][2];

            // Move Matrix 1 pointer
            i++;
            k++;
        }

        // Copy Matrix 2 element
        else
        {
            arr[k][0] = m2.arr[j][0];
            arr[k][1] = m2.arr[j][1];
            arr[k][2] = m2.arr[j][2];

            // Move Matrix 2 pointer
            j++;
            k++;
        }
    }

    // Copy remaining Matrix 1 elements
    while (i < m1.n)
    {
        arr[k][0] = m1.arr[i][0];
        arr[k][1] = m1.arr[i][1];
        arr[k][2] = m1.arr[i][2];

        i++;
        k++;
    }

    // Copy remaining Matrix 2 elements
    while (j < m2.n)
    {
        arr[k][0] = m2.arr[j][0];
        arr[k][1] = m2.arr[j][1];
        arr[k][2] = m2.arr[j][2];

        j++;
        k++;
    }

    // Update result size
    n = k;

    // Display addition result
    cout << "\nAddition of Sparse Matrices:\n";
    display();
}


// Multiply two sparse matrices
void matrix::multiply(matrix m1, matrix m2)
{
    // Create temporary result matrix
    int temp[10][10] = {0};

    // Compare elements for multiplication
    for (int i = 0; i < m1.n; i++)
    {
        for (int j = 0; j < m2.n; j++)
        {
            // Check column of M1 equals row of M2
            if (m1.arr[i][1] == m2.arr[j][0])
            {
                // Get result row and column
                int row = m1.arr[i][0];
                int col = m2.arr[j][1];

                // Check valid matrix position
                if (row >= 0 && row < 10 &&
                    col >= 0 && col < 10)
                {
                    // Multiply and accumulate value
                    temp[row][col] +=
                        m1.arr[i][2] * m2.arr[j][2];
                }
            }
        }
    }

    // Reset result element count
    n = 0;

    // Convert normal matrix to sparse form
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            // Store non-zero result
            if (temp[i][j] != 0)
            {
                // Prevent array overflow
                if (n >= 10)
                {
                    cout << "Result contains more than 10 "
                         << "non-zero elements.\n";
                    return;
                }

                // Store row, column and value
                arr[n][0] = i;
                arr[n][1] = j;
                arr[n][2] = temp[i][j];

                n++;
            }
        }
    }

    // Display multiplication result
    cout << "\nMultiplication of Sparse Matrices:\n";
    display();
}


// Perform simple transpose
void matrix::transpose()
{
    // Temporary variable for swapping
    int temp;

    // Swap row and column
    for (int i = 0; i < n; i++)
    {
        temp = arr[i][0];
        arr[i][0] = arr[i][1];
        arr[i][1] = temp;
    }

    // Display transpose result
    cout << "\nTransposed Matrix:\n";
    display();
}


// Perform fast transpose
void matrix::fastTranspose()
{
    // Create temporary transpose matrix
    int result[10][3] = {0};

    // Count elements in each column
    int count[10] = {0};

    // Store starting position of each column
    int pos[10] = {0};

    // Find maximum column number
    int maxCol = 0;

    // Scan all elements for maximum column
    for (int i = 0; i < n; i++)
    {
        if (arr[i][1] > maxCol)
        {
            maxCol = arr[i][1];
        }
    }

    // Count elements column-wise
    for (int i = 0; i < n; i++)
    {
        int col = arr[i][1];

        // Check valid column
        if (col >= 0 && col < 10)
        {
            count[col]++;
        }
    }

    // Calculate starting positions
    pos[0] = 0;

    // Generate position array
    for (int i = 1; i <= maxCol; i++)
    {
        pos[i] = pos[i - 1] + count[i - 1];
    }

    // Place elements in transposed position
    for (int i = 0; i < n; i++)
    {
        int col = arr[i][1];

        // Get position for current element
        int p = pos[col];

        // Swap row and column
        result[p][0] = arr[i][1];
        result[p][1] = arr[i][0];

        // Copy value
        result[p][2] = arr[i][2];

        // Move position forward
        pos[col]++;
    }

    // Copy transpose back to original array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j] = result[i][j];
        }
    }

    // Display fast transpose
    cout << "\nFast Transposed Matrix:\n";
    display();
}


// Transpose Matrix 1 and multiply with Matrix 2
void matrix::getTranspose(matrix m1, matrix m2)
{
    // Create temporary transpose matrix
    matrix t1;

    // Copy number of elements
    t1.n = m1.n;

    // Generate transpose of Matrix 1
    for (int i = 0; i < m1.n; i++)
    {
        // Swap row and column
        t1.arr[i][0] = m1.arr[i][1];
        t1.arr[i][1] = m1.arr[i][0];

        // Copy value
        t1.arr[i][2] = m1.arr[i][2];
    }

    // Display transpose of Matrix 1
    cout << "\nTranspose of Matrix 1:\n";
    t1.display();

    // Create temporary multiplication matrix
    int temp[10][10] = {0};

    // Multiply Transpose(M1) with M2
    for (int i = 0; i < t1.n; i++)
    {
        for (int j = 0; j < m2.n; j++)
        {
            // Check multiplication condition
            if (t1.arr[i][1] == m2.arr[j][0])
            {
                // Get result row and column
                int row = t1.arr[i][0];
                int col = m2.arr[j][1];

                // Check valid position
                if (row >= 0 && row < 10 &&
                    col >= 0 && col < 10)
                {
                    // Multiply and accumulate
                    temp[row][col] +=
                        t1.arr[i][2] * m2.arr[j][2];
                }
            }
        }
    }

    // Reset result count
    n = 0;

    // Convert result to sparse form
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            // Store non-zero values
            if (temp[i][j] != 0)
            {
                // Prevent array overflow
                if (n >= 10)
                {
                    cout << "Result contains more than 10 "
                         << "non-zero elements.\n";
                    return;
                }

                // Store result element
                arr[n][0] = i;
                arr[n][1] = j;
                arr[n][2] = temp[i][j];

                n++;
            }
        }
    }

    // Display final result
    cout << "\nTranspose(Matrix 1) × Matrix 2:\n";
    display();
}


// Program execution starts here
int main()
{
    // Create two input matrices
    matrix m[2];

    // Create result matrix
    matrix result;

    // Store menu choice
    int ch;

    // Keep displaying menu
    while (true)
    {
        // Display menu
        cout << "       SPARSE MATRIX OPERATIONS\n";

        cout << "1. Insert Data\n";
        cout << "2. Display Sparse Matrices\n";
        cout << "3. Fast Transpose\n";
        cout << "4. Addition of Two Sparse Matrices\n";
        cout << "5. Multiplication of Two Sparse Matrices\n";
        cout << "6. Transpose(Matrix 1) × Matrix 2\n";
        cout << "7. Exit\n";

        // Read user's choice
        cout << "\nEnter your choice: ";
        cin >> ch;

        // Execute selected operation
        switch (ch)
        {
            // Insert data into both matrices
            case 1:
                for (int i = 0; i < 2; i++)
                {
                    cout << "\nEnter data for Matrix "
                         << i + 1 << ":\n";

                    m[i].getdata();
                }
                break;


            // Display both matrices
            case 2:
                for (int i = 0; i < 2; i++)
                {
                    cout << "\nSparse Matrix "
                         << i + 1 << ":\n";

                    m[i].display();
                }
                break;


            // Perform fast transpose
            case 3:
                for (int i = 0; i < 2; i++)
                {
                    cout << "\nFast Transpose of Sparse Matrix "
                         << i + 1 << ":\n";

                    m[i].fastTranspose();
                }
                break;


            // Add both matrices
            case 4:
                result.add(m[0], m[1]);
                break;


            // Multiply both matrices
            case 5:
                result.multiply(m[0], m[1]);
                break;


            // Transpose Matrix 1 and multiply with Matrix 2
            case 6:
                result.getTranspose(m[0], m[1]);
                break;


            // Exit the program
            case 7:
                cout << "\nProgram terminated.\n";
                return 0;


            // Handle invalid menu choice
            default:
                cout << "\nInvalid choice! "
                     << "Please enter a number from 1 to 7.\n";
        }
    }

    return 0;
}
