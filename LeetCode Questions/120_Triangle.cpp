// https://leetcode.com/problems/triangle/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    int solve(int i, int j, int n, vector<vector<int>> &triangle, vector<vector<int>> &dp)
    {
        if (i == n - 1)
            return triangle[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        int ind0 = triangle[i][j] + solve(i + 1, j, n, triangle, dp);
        int ind1 = triangle[i][j] + solve(i + 1, j + 1, n, triangle, dp);
        return dp[i][j] = min(ind0, ind1);
    }

    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, 0, n, triangle, dp);
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        Solution ob;
        int n;
        cin >> n;
        vector<vector<int>> triangle(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= i; j++)
                cin >> triangle[i][j];
        cout << ob.minimumTotal(triangle) << endl;
        }
    return 0;
}