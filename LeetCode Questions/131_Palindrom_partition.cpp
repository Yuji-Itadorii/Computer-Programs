// https://leetcode.com/problems/palindrome-partitioning/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
private:
    int dp[20][20];

    bool isPalindrome(const string &s, int start, int end)
    {
        if (dp[start][end] != -1)
        {
            return dp[start][end];
        }
        int i = start, j = end;
        while (i <= j)
        {
            if (s[i++] != s[j--])
                return false;
        }
        return dp[start][end] = true;
    }

    void dfs(int index, string &s, vector<string> &path, vector<vector<string>> &ret)
    {
        if (index == s.size())
        {
            ret.push_back(path);
            return;
        }
        for (int i = index; i < s.size(); ++i)
        {
            if (isPalindrome(s, index, i))
            {
                path.push_back(s.substr(index, i - index + 1));
                dfs(i + 1, s, path, ret);
                path.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ret;
        if (s.empty())
            return ret;
        memset(dp, -1, sizeof(dp));

        vector<string> path;
        dfs(0, s, path, ret);

        return ret;
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        Solution ob;
        string s;
        cin >> s;
        vector<vector<string>> ans = ob.partition(s);
        for (int i = 0; i < ans.size(); ++i)
        {
            for (int j = 0; j < ans[i].size(); ++j)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}