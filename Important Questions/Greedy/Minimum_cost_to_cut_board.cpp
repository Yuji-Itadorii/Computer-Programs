// https://practice.geeksforgeeks.org/problems/minimum-cost-to-cut-a-board-into-squares/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int minimumCostOfBreaking(vector<int> x, vector<int> y, int M, int N)
    {
        // Write your code here
        sort(x.begin(), x.end(), greater<int>());
        sort(y.begin(), y.end(), greater<int>());
        int h = 1, v = 1;
        int cost = 0;
        int i = 0, j = 0;
        M--;
        N--;
        while (i < M and j < N)
        {
            if (x[i] > y[j])
            {
                cost += x[i] * h;
                i++;
                v++;
            }
            else
            {
                cost += y[j] * v;
                j++;
                h++;
            }
        }

        while (i < M)
        {
            cost += x[i] * h;
            i++;
            v++;
        }

        while (j < N)
        {
            cost += y[j] * v;
            j++;
            h++;
        }

        return cost;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        vector<int> X(m - 1), Y(n - 1);
        for (int i = 0; i < m - 1; i++)
        {
            cin >> X[i];
        }
        for (int i = 0; i < n - 1; i++)
        {
            cin >> Y[i];
        }
        Solution ob;
        int ans = ob.minimumCostOfBreaking(X, Y, m, n);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends