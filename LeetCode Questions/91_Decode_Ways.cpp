// https://leetcode.com/problems/decode-ways/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{

    int solve(string &s, int i, vector<int> &dp)
    {

        if (i < s.size() and s[i] == '0')
        {
            return 0;
        }

        if (i >= s.size())
        {
            return 1;
        }

        if (dp[i] != -1)
        {
            return dp[i];
        }

        int opt1 = 0, opt2 = 0;

        if (i + 1 < s.size() && ((s[i] == '1' && s[i + 1] <= '9') || (s[i] == '2' && s[i + 1] < '7')))
        {
            opt1 = solve(s, i + 2, dp);
        }

        opt2 = solve(s, i + 1, dp);

        return dp[i] = (opt1 + opt2);
    }

public:
    int numDecodings(string s)
    {
        int i = 0;
        // while(s[i] == '0'){
        //     i++;
        // }

        vector<int> dp(s.size(), -1);

        return solve(s, i, dp);
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        Solution s;
        string str;
        cin >> str;
        cout << s.numDecodings(str) << endl;
    }
    return 0;
}