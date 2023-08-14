// https://practice.geeksforgeeks.org/problems/find-all-possible-palindromic-partitions-of-a-string/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{

    bool isPalindrome(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i <= j)
        {
            if (s[i] == s[j])
            {
                i++, j--;
                continue;
            }
            return false;
        }
        return true;
    }

    void helper(string &S, vector<vector<string>> &res, int i, vector<string> &copy)
    {
        if (i >= S.length())
        {
            res.push_back(copy);
            return;
        }
        string str = "";
        for (int j = i; j < S.size(); j++)
        {
            str += S[j];
            if (isPalindrome(str))
            {
                copy.push_back(str);
                helper(S, res, j + 1, copy);
                copy.pop_back();
            }
        }
    }

public:
    vector<vector<string>> allPalindromicPerms(string S)
    {
        // code here
        vector<vector<string>> res;
        vector<string> copy;
        helper(S, res, 0, copy);
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
        string S;

        cin >> S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);

        for (int i = 0; i < ptr.size(); i++)
        {
            for (int j = 0; j < ptr[i].size(); j++)
            {
                cout << ptr[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends