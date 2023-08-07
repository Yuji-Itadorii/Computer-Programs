// https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid
#define UNASSIGNED 0

// N is used for the size of Sudoku grid.
// Size will be NxN
#define N 9

// } Driver Code Ends
class Solution
{

private:
    bool isValid(int i, int j, int val, int grid[N][N])
    {
        for (int k = 0; k < N; k++)
        {
            if (grid[i][k] == val || grid[k][j] == val)
            {
                return false;
            }
        }

        int s = sqrt(N);
        int r = i - i % s;
        int c = j - j % s;
        for (i = 0; i < s; i++)
        {
            for (j = 0; j < s; j++)
            {
                if (grid[i + r][j + c] == val)
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool solve(int grid[N][N])
    {

        int i = 0, j = 0;
        bool flag = false;

        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                if (grid[i][j] == 0)
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                break;
            }
        }

        //  cout<<i<<" "<<j<<endl;

        if (i == N and j == N)
        {
            return true;
        }

        for (int val = 1; val <= N; val++)
        {
            if (isValid(i, j, val, grid))
            {
                grid[i][j] = val;
                if (solve(grid))
                {
                    return true;
                }
                grid[i][j] = 0;
            }
        }

        return false;
    }

public:
    // Function to find a solved Sudoku.
    bool SolveSudoku(int grid[N][N])
    {
        // Your code here
        // return true;
        return solve(grid);
    }

    // Function to print grids of the Sudoku.
    void printGrid(int grid[N][N])
    {
        // Your code here
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << grid[i][j] << " ";
            }
            // cout<<endl;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int grid[N][N];

        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                cin >> grid[i][j];

        Solution ob;

        if (ob.SolveSudoku(grid) == true)
            ob.printGrid(grid);
        else
            cout << "No solution exists";

        cout << endl;
    }

    return 0;
}
// } Driver Code Ends