// https://leetcode.com/problems/search-a-2d-matrix-ii/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int i = 0, j = matrix[0].size() - 1;
        while (i < matrix.size() && j >= 0)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
            else if (matrix[i][j] > target)
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
    ll t;
    cin >> t;
    while (t--)
    {
        Solution s;
        vector<vector<int>> matrix;
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            vector<int> temp;
            for (int j = 0; j < m; j++)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            matrix.push_back(temp);
        }
        int target;
        cin >> target;
        cout << s.searchMatrix(matrix, target) << endl;
    }
    return 0;
}