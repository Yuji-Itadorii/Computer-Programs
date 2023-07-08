// https://www.geeksforgeeks.org/minimize-cash-flow-among-given-set-friends-borrowed-money/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
    int findMin(vector<int> &amt, int n)
    {
        int min = 1e9;
        int mini = -1;
        for (int i = 0; i < n; i++)
        {
            if (amt[i] < min)
            {
                min = amt[i];
                mini = i;
            }
        }
        return mini;
    }
    int findMax(vector<int> &amt, int n)
    {
        int max = -1e9;
        int maxi = -1;
        for (int i = 0; i < n; i++)
        {
            if (amt[i] > max)
            {
                max = amt[i];
                maxi = i;
            }
        }
        return maxi;
    }
    void fun(vector<int> &amt, int n, vector<vector<int>> &ans)
    {
        int mini = findMin(amt, n), maxi = findMax(amt, n);
        if (amt[mini] == 0 && amt[maxi] == 0)
            return;
        int a = min(-amt[mini], amt[maxi]);
        amt[mini] += a;
        amt[maxi] -= a;
        ans[mini][maxi] += a;
        fun(amt, n, ans);
    }

public:
    vector<vector<int>> minCashFlow(vector<vector<int>> &transaction, int n)
    {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        vector<int> amt(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                amt[i] = amt[i] + transaction[j][i] - transaction[i][j];
            }
        }
        fun(amt, n, ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> g(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> g[i][j];
        }
        Solution s;
        vector<vector<int>> r = s.minCashFlow(g, n);
        for (auto j : r)
        {
            for (auto i : j)
                cout << i << " ";
            cout << endl;
        }
        // cout<<endl;
    }
    return 0;
}
// } Driver Code Ends