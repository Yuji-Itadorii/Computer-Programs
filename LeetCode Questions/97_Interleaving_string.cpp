// https://leetcode.com/problems/interleaving-string/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{

    unordered_map<string, bool> memo;

    bool solve(string &s1, string &s2, string &s3, int i, int j, int k)
    {

        if (k >= s3.size())
        {
            return true;
        }

        string key = to_string(i) + "|" + to_string(j) + "|" + to_string(k);
        if (memo.find(key) != memo.end())
        {
            return memo[key];
        }

        if (i >= s1.size() and j >= s2.size() and k < s3.size() - 1)
        {
            return false;
        }

        bool opt1 = false, opt2 = false, opt3 = false;

        if (i < s1.size() and s1[i] == s3[k])
        {
            opt1 = solve(s1, s2, s3, i + 1, j, k + 1) || solve(s1, s2, s3, i + 1, j, k);
        }

        if (j < s2.size() and s2[j] == s3[k])
        {
            opt2 = solve(s1, s2, s3, i, j + 1, k + 1) || solve(s1, s2, s3, i, j + 1, k);
        }

        return memo[key] = (opt1 || opt2);
    }

public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.size() + s2.size() != s3.size())
        {
            return false;
        }

        return solve(s1, s2, s3, 0, 0, 0);
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        Solution s;
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        cout << s.isInterleave(s1, s2, s3) << endl;
    }
    return 0;
}