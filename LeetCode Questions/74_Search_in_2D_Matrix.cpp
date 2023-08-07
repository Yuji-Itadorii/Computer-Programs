// https://leetcode.com/problems/search-a-2d-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int x)
    {
        int i = 0, j = matrix[0].size() - 1;
        while (i < matrix.size() && j >= 0)
        {
            if (matrix[i][j] == x)
            {
                return true;
            }
            else if (matrix[i][j] > x)
            {
                j--;
            }
            else
            {
                i++;
            }
        }

        return false;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix = {{1, 3, 5, 7},
                                  {10, 11, 16, 20},
                                  {23, 30, 34, 50}};

    cout << s.searchMatrix(matrix, 3) << endl;

        return 0;
}