// https://practice.geeksforgeeks.org/problems/power-set4302/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<string> AllPossibleStrings(string s)
    {
        // Code here
        vector<string> v;
        int n = s.length();

        for (int num = 0; num < pow(2, n); num++)
        {
            string sub;
            for (int i = 0; i < n; i++)
            {
                if (num & 1 << i)
                {
                    sub = sub + s[i];
                }
            }
            if (!sub.empty())
                v.push_back(sub);
        }
        sort(v.begin(), v.end());
        return v;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string s;
        cin >> s;
        Solution ob;
        vector<string> res = ob.AllPossibleStrings(s);
        for (auto i : res)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends