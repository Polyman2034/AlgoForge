/*
Question:
Design and implement a program for 2 x 2 Sudoku Solver
using Recursive Backtracking.

Self-Study:
Additional Practice:
3 x 3 Sudoku Solver using Recursive Backtracking.
*/


#include <iostream>
using namespace std;


// ======================================================
//                    2 x 2 SUDOKU
// ======================================================

class Sudoku2x2
{
private:

    int board[2][2];


    // CHECK WHETHER NUMBER IS SAFE
    bool isSafe(int row, int col, int num)
    {
        // Check row
        for (int i = 0; i < 2; i++)
        {
            if (board[row][i] == num)
                return false;
        }

        // Check column
        for (int i = 0; i < 2; i++)
        {
            if (board[i][col] == num)
                return false;
        }

        return true;
    }


    // RECURSIVE BACKTRACKING
    bool solve()
    {
        int row = -1;
        int col = -1;
        bool emptyFound = false;


        // Find empty cell
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                if (board[i][j] == 0)
                {
                    row = i;
                    col = j;
                    emptyFound = true;
                    break;
                }
            }

            if (emptyFound)
                break;
        }


        // No empty cell means Sudoku is solved
        if (!emptyFound)
            return true;


        // Try numbers 1 to 2
        for (int num = 1; num <= 2; num++)
        {
            if (isSafe(row, col, num))
            {
                board[row][col] = num;


                // Recursive call
                if (solve())
                    return true;


                // Backtracking
                board[row][col] = 0;
            }
        }

        return false;
    }


public:

    // CONSTRUCTOR
    Sudoku2x2()
    {
        int puzzle[2][2] =
        {
            {1, 0},
            {0, 1}
        };


        // Copy puzzle into board
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                board[i][j] = puzzle[i][j];
            }
        }
    }


    // DISPLAY
    void display()
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cout << board[i][j] << " ";
            }

            cout << endl;
        }
    }


    // SOLVE SUDOKU
    void solveSudoku()
    {
        if (solve())
            cout << "2 x 2 Sudoku solved successfully!\n";
        else
            cout << "No solution exists.\n";
    }
};


// ======================================================
//                    3 x 3 SUDOKU
// ======================================================

class Sudoku3x3
{
private:

    int board[3][3];


    // CHECK WHETHER NUMBER IS SAFE
    bool isSafe(int row, int col, int num)
    {
        // Check row
        for (int i = 0; i < 3; i++)
        {
            if (board[row][i] == num)
                return false;
        }


        // Check column
        for (int i = 0; i < 3; i++)
        {
            if (board[i][col] == num)
                return false;
        }


        return true;
    }


    // RECURSIVE BACKTRACKING
    bool solve()
    {
        int row = -1;
        int col = -1;
        bool emptyFound = false;


        // Find empty cell
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == 0)
                {
                    row = i;
                    col = j;
                    emptyFound = true;
                    break;
                }
            }

            if (emptyFound)
                break;
        }


        // No empty cell means Sudoku is solved
        if (!emptyFound)
            return true;


        // Try numbers 1 to 3
        for (int num = 1; num <= 3; num++)
        {
            if (isSafe(row, col, num))
            {
                board[row][col] = num;


                // Recursive call
                if (solve())
                    return true;


                // Backtracking
                board[row][col] = 0;
            }
        }

        return false;
    }


public:

    // CONSTRUCTOR
    Sudoku3x3()
    {
        int puzzle[3][3] =
        {
            {1, 0, 3},
            {0, 3, 1},
            {3, 1, 0}
        };


        // Copy puzzle into board
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                board[i][j] = puzzle[i][j];
            }
        }
    }


    // DISPLAY
    void display()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << board[i][j] << " ";
            }

            cout << endl;
        }
    }


    // SOLVE SUDOKU
    void solveSudoku()
    {
        if (solve())
            cout << "3 x 3 Sudoku solved successfully!\n";
        else
            cout << "No solution exists.\n";
    }
};


// ======================================================
//                       MAIN
// ======================================================

int main()
{
    int choice;


    cout << "=====================================\n";
    cout << "          SUDOKU SOLVER\n";
    cout << "=====================================\n";

    cout << "1. Solve 2 x 2 Sudoku\n";
    cout << "2. Solve 3 x 3 Sudoku\n";

    cout << "Enter your choice: ";
    cin >> choice;


    // 2 x 2 Sudoku
    if (choice == 1)
    {
        Sudoku2x2 sudoku;


        cout << "\nOriginal 2 x 2 Sudoku:\n";
        sudoku.display();


        cout << endl;

        sudoku.solveSudoku();


        cout << "\nSolved 2 x 2 Sudoku:\n";
        sudoku.display();
    }


    // 3 x 3 Sudoku
    else if (choice == 2)
    {
        Sudoku3x3 sudoku;


        cout << "\nOriginal 3 x 3 Sudoku:\n";
        sudoku.display();


        cout << endl;

        sudoku.solveSudoku();


        cout << "\nSolved 3 x 3 Sudoku:\n";
        sudoku.display();
    }


    else
    {
        cout << "Invalid choice!\n";
    }


    return 0;
}
