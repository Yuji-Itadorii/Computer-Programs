// https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-given-n-ranges/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<vector<int>> mergeIntervals(vector<vector<int>> &range)
    {
        int n = range.size();
        vector<vector<int>> fin;
        for (int i = 0; i < n - 1; i++)
        {
            if (range[i][1] >= range[i + 1][0])
            {
                range[i + 1][0] = min(range[i][0], range[i + 1][0]);
                range[i + 1][1] = max(range[i][1], range[i + 1][1]);
            }
            else
            {
                fin.push_back(range[i]);
            }
        }
        fin.push_back(range[n - 1]);
        return fin;
    }

    vector<int> kthSmallestNum(vector<vector<int>> &range, vector<int> queries)
    {
        // Write your code here

        sort(range.begin(), range.end());
        vector<vector<int>> merged = mergeIntervals(range);

        set<int> s;
        int cumsum = 0;
        for (auto cur_range : merged)
        {
            int num_ele = cur_range[1] - cur_range[0] + 1;
            cumsum += num_ele;
            s.insert(cumsum);
        }

        vector<int> fin;

        for (auto q : queries)
        {
            auto it = s.lower_bound(q);
            if (it == s.end())
                fin.push_back(-1);

            // if the required element is in first range
            else if (it == s.begin())
            {
                fin.push_back(merged[0][0] + q - 1);
            }

            // if the required element is in ith range. then discard previous range elements
            //  if previous elements are prevele. then look for k=q-prevele in the current range
            else
            {
                int prevele = *prev(it);
                int kth = q - prevele;
                int idx = distance(s.begin(), it);
                fin.push_back(merged[idx][0] + kth - 1);
            }
        }

        return fin;
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
        vector<vector<int>> range(n, vector<int>(2, 0));
        for (int i = 0; i < n; i++)
        {
            cin >> range[i][0] >> range[i][1];
        }
        int q;
        cin >> q;
        vector<int> queries;
        for (int i = 0; i < q; i++)
        {
            int x;
            cin >> x;
            queries.push_back(x);
        }
        Solution ob;
        vector<int> ans = ob.kthSmallestNum(range, queries);
        for (auto it : ans)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends