// https://practice.geeksforgeeks.org/problems/combination-sum-1587115620/1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{

private:
    void solve(int i, vector<int> &arr, int sum, int b, vector<int> &v,
               vector<vector<int>> &ans)
    {

        if (i == arr.size() || sum >= b)
        {
            if (sum == b)
            {
                ans.push_back(v);
            }
            return;
        }

        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];
            v.push_back(arr[j]);
            solve(j, arr, sum, b, v, ans);
            // solve(j+1 , arr, sum , b, v, ans);
            sum -= arr[j];
            v.pop_back();
        }
    }

public:
    // Function to return a list of indexes denoting the required
    // combinations whose sum is equal to given number.
    vector<vector<int>> combinationSum(vector<int> &A, int B)
    {
        // Your code here

        sort(A.begin(), A.end());

        A.erase(unique(A.begin(), A.end()), A.end());

        vector<vector<int>> ans;

        vector<int> v;

        solve(0, A, 0, B, v, ans);

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
        vector<int> A;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            A.push_back(x);
        }
        int sum;
        cin >> sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
        if (result.size() == 0)
        {
            cout << "Empty";
        }
        for (int i = 0; i < result.size(); i++)
        {
            cout << '(';
            for (int j = 0; j < result[i].size(); j++)
            {
                cout << result[i][j];
                if (j < result[i].size() - 1)
                    cout << " ";
            }
            cout << ")";
        }
        cout << "\n";
    }
}
// } Driver Code Ends