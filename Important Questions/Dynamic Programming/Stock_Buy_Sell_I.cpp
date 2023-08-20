// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    int maxProfit(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 1)
        {
            return 0;
        }
        int miniPrice = arr[0];
        int profit = 0;
        for (int i = 1; i < n; i++)
        {
            profit = max(profit, arr[i] - miniPrice);
            miniPrice = min(miniPrice, arr[i]);
        }

        return profit;
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << ob.maxProfit(arr) << endl;
    }
    return 0;
}