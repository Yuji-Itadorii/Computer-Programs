// https://practice.geeksforgeeks.org/problems/assembly-line-scheduling/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{

private:
    int solve(vector<vector<int>> &arr, vector<vector<int>> &cross_Time, vector<int> &e, vector<int> &x)
    {
        int T1[arr[0].size()], T2[arr[0].size()];

        T1[0] = e[0] + arr[0][0];
        T2[0] = e[1] + arr[1][0];

        for (int i = 1; i < arr[0].size(); i++)
        {
            T1[i] = min((T1[i - 1] + arr[0][i]),
                        (T2[i - 1] + arr[0][i] + cross_Time[1][i]));
            // cout<<T1[i]<<" ";
            T2[i] = min((T2[i - 1] + arr[1][i]),
                        (T1[i - 1] + arr[1][i] + cross_Time[0][i]));
            // cout<<T2[i]<<endl;
        }

        return min((T1[arr[0].size() - 1] + x[0]), (T2[arr[0].size() - 1] + x[1]));
    }

public:
    int carAssembly(vector<vector<int>> &a, vector<vector<int>> &T, vector<int> &e, vector<int> &x)
    {
        // Code Here
        return solve(a, T, e, x);
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
        vector<vector<int>> a(2, vector<int>(n)), T(2, vector<int>(n));
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> T[i][j];
            }
        }
        vector<int> e(2), x(2);
        for (int i = 0; i < 2; i++)
        {
            cin >> e[i];
        }
        for (int i = 0; i < 2; i++)
        {
            cin >> x[i];
        }

        Solution ob;
        int ans = ob.carAssembly(a, T, e, x);

        cout << ans << endl;
    }
}
// } Driver Code Ends