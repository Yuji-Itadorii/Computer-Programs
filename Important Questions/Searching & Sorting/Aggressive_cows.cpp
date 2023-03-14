// https://practice.geeksforgeeks.org/problems/aggressive-cows/1

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int check(vector<int> &arr, int mid, int k)
    {
        int temp = arr[0], count = 1;
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] - temp >= mid)
            {
                temp = arr[i];
                count++;
            }
            if (count == k)
            {
                return true;
            }
        }
        return false;
    }

    int solve(int n, int k, vector<int> &arr)
    {

        // Write your code here
        sort(arr.begin(), arr.end());
        if (k == 2)
        {
            return arr[n - 1] - arr[0];
        }
        int diff_max = arr[n - 1] - arr[0], ans = 1; // 8
        int diff_min = 1, mid;
        while (diff_min <= diff_max)
        {
            mid = (diff_min + diff_max) / 2; // 4
            if (check(arr, mid, k))
            {
                diff_min = mid + 1;
                ans = max(ans, mid);
            }
            else
            {
                diff_max = mid - 1;
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--)
    {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++)
        {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends