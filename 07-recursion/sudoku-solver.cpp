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



//  N x N SUDOKU


class SudokuNxN
{
private:

    int N;
    int **board;


    // CHECK WHETHER NUMBER IS SAFE
    bool isSafe(int row, int col, int num)
    {
        // Check row
        for (int i = 0; i < N; i++)
        {
            if (board[row][i] == num)
                return false;
        }

        // Check column
        for (int i = 0; i < N; i++)
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
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
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


        // Try numbers from 1 to N
        for (int num = 1; num <= N; num++)
        {
            if (isSafe(row, col, num))
            {
                // Place number
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
    SudokuNxN(int n)
    {
        N = n;

        board = new int*[N];

        for (int i = 0; i < N; i++)
        {
            board[i] = new int[N];
        }
    }


    // DESTRUCTOR
    ~SudokuNxN()
    {
        for (int i = 0; i < N; i++)
        {
            delete[] board[i];
        }

        delete[] board;
    }


    // TAKE PUZZLE FROM USER
    void inputPuzzle()
    {
        cout << "\nEnter the "
             << N << " x " << N
             << " Sudoku puzzle:\n";

        cout << "Enter 0 for empty cells.\n\n";


        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> board[i][j];
            }
        }
    }


    // DISPLAY
    void display()
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
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
        {
            cout << "\nSudoku solved successfully!\n";
        }
        else
        {
            cout << "\nNo solution exists.\n";
        }
    }
};



//MAIN


int main()
{
    int N;


   
    cout << "SUDOKU SOLVER\n";
    


    // TAKE N FROM USER
    cout << "Enter value of N: ";
    cin >> N;


    // Check valid N
    if (N <= 0)
    {
        cout << "Invalid value of N!\n";
        return 0;
    }


    // Create Sudoku
    SudokuNxN sudoku(N);


    // Sudoko Timer from user from user
    sudoku.inputPuzzle();


    // Display original 
    cout << "\nOriginal Sudoku:\n";
    sudoku.display();


    // Solve
    sudoku.solveSudoku();


    // Display solved puzzle
    cout << "\nSolved Sudoku:\n";
    sudoku.display();


    return 0;
}
