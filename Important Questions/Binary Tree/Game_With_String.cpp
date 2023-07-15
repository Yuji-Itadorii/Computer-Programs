// https://practice.geeksforgeeks.org/problems/game-with-string4100/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int minValue(string s, int k)
    {
        // code here
        unordered_map<char, int> m;

        for (int i = 0; i < s.size(); i++)
        {
            m[s[i]]++;
        }

        priority_queue<pair<int, char>> p;

        for (auto x : m)
        {
            p.push({x.second, x.first});
        }

        for (int i = 0; i < k; i++)
        {
            auto x = p.top();
            p.pop();
            x.first--;

            if (x.first != 0)
            {
                p.push(x);
            }
        }

        int ans = 0;

        while (!p.empty())
        {
            auto x = p.top();
            p.pop();

            ans += pow(x.first, 2);
        }

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
        string s;
        int k;
        cin >> s >> k;

        Solution ob;
        cout << ob.minValue(s, k) << "\n";
    }
    return 0;
}
// } Driver Code Ends