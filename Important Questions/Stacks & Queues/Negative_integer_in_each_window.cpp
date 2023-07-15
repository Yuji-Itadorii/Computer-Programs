// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                            long long int n, long long int k);

// Driver program to test above functions
int main()
{
    long long int t, i;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

vector<long long> printFirstNegativeInteger(long long int arr[],
                                            long long int n, long long int k)
{

    queue<long long int> q;

    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            q.push(arr[i]);
        }
    }

    vector<long long int> ans;

    if (q.empty())
        ans.push_back(0);
    else
    {
        ans.push_back(q.front());
    }

    for (int i = k; i < n; i++)
    {
        if (arr[i] < 0)
        {
            q.push(arr[i]);
        }

        if (arr[i - k] < 0)
        {
            q.pop();
        }

        if (q.empty())
        {
            ans.push_back(0);
        }
        else
        {
            ans.push_back(q.front());
        }
    }

    return ans;
}