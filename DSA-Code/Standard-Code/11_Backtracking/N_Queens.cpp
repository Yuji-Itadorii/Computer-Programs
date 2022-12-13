#include <bits/stdc++.h>
using namespace std;

#define N 4
bool board[N][N];

void printMatrix()
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

bool isSafe(int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        if (board[row][i])
        {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }

    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }

    return true;
}

bool solveRecursive(int col)
{
    if (col == N) 
        return true; 
  
    for (int i = 0; i < N; i++) { 
     
        if (isSafe(i, col)) { 
            board[i][col] = 1; 
  
            if (solveRecursive(col + 1)) 
                return true; 
  
            board[i][col] = 0;
        } 
    } 
  
    return false; 
}

bool solve()
{
    if (solveRecursive(0) == false)
    {
        return false;
    }

    printMatrix();
    return true;
}

int main()
{

    if (solve())
    {
        cout << "Is the solution " << endl;
    }
    else
    {
        cout << "No solution found!!!" << endl;
    }

    return 0;
}