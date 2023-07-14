// https://practice.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> rearrangeQueue(queue<int> &q)
    {
        int n = q.size();
        vector<int> res(n);

        for (int i = 0; i < n; i += 2)
        {
            int x = q.front();
            q.pop();
            if (i % 2 == 0)
            {
                res[i] = x;
            }
            else
            {
                q.push(x);
            }
        }

        for (int i = 1; i < n; i += 2)
        {
            int x = q.front();
            q.pop();
            if (i % 2 == 1)
            {
                res[i] = x;
            }
            else
            {
                q.push(x);
            }
        }

        return res;
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

        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans = ob.rearrangeQueue(q);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends