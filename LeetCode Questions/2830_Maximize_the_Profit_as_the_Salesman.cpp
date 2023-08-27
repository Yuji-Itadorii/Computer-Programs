// https://leetcode.com/problems/maximize-the-profit-as-the-salesman/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class comp
{
public:
    // Comparator function
    bool operator()(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
        {
            return a[2] > b[2];
        }
        return a[0] < b[0];
    }
};

class Solution
{
    int solve(int idx, vector<vector<int>> &offers, vector<int> &dp)
    {

        if (idx == offers.size())
            return 0;
        if (dp[idx] != -1)
            return dp[idx];

        int notTake = solve(idx + 1, offers, dp);

        int low = idx + 1, high = offers.size() - 1;
        int next_idx = offers.size();

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (offers[mid][0] > offers[idx][1])
            {
                high = mid - 1;
                next_idx = mid;
            }
            else
            {
                low = mid + 1;
            }
        }

        int take = offers[idx][2] + solve(next_idx, offers, dp);
        return dp[idx] = max(take, notTake);
    }

public:
    int maximizeTheProfit(int n, vector<vector<int>> &offers)
    {
        sort(offers.begin(), offers.end(), comp());
        int m = offers.size();
        vector<int> dp(m, -1);
        return solve(0, offers, dp);
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> offers(n, vector<int>(3));
        for (int i = 0; i < n; i++)
        {
            cin >> offers[i][0] >> offers[i][1] >> offers[i][2];
        }
        Solution ob;
        cout << ob.maximizeTheProfit(n, offers) << endl;
        }
    return 0;
}