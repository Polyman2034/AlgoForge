#include <iostream>
using namespace std;


class Sudoku
{
private:
    int board[3][3];


    // Checks whether a number can be placed at a position
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


    // Backtracking function
    bool solve()
    {
        int row = -1;
        int col = -1;
        bool emptyFound = false;


        // Find an empty cell
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


                // Recursively solve remaining cells
                if (solve())
                    return true;


                // Backtrack
                board[row][col] = 0;
            }
        }


        return false;
    }


public:
    // Constructor
    Sudoku()
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


    void solveSudoku()
    {
        if (solve())
            cout << "Sudoku solved successfully!\n";
        else
            cout << "No solution exists.\n";
    }
};


int main()
{
    Sudoku sudoku;


    cout << "Original Sudoku:\n";
    sudoku.display();


    sudoku.solveSudoku();


    cout << "\nSolved Sudoku:\n";
    sudoku.display();


    return 0;
}

