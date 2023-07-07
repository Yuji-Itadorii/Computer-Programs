// https://practice.geeksforgeeks.org/problems/buy-maximum-stocks-if-i-stocks-can-be-bought-on-i-th-day/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int buyMaximumProducts(int n, int k, int price[])
    {
        // Write your code here
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++)
        {
            arr.push_back({price[i], i + 1});
        }

        sort(arr.begin(), arr.end());

        // int i =0;
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i].first * arr[i].second < k)
            {
                count += arr[i].second;
                k -= arr[i].first * arr[i].second;
            }
            else
            {
                count += k / arr[i].first;
                break;
            }
        }

        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int price[n];
        for (int i = 0; i < n; i++)
        {
            cin >> price[i];
        }
        Solution ob;
        int ans = ob.buyMaximumProducts(n, k, price);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends