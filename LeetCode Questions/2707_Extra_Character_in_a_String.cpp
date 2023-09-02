// https://leetcode.com/problems/extra-characters-in-a-string/description/?envType=daily-question&envId=2023-09-02

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    int solve(string &s, unordered_map<string, int> &mp, int index, vector<int> &dp)
    {
        if (index >= s.size())
            return 0;
        if (dp[index] != -1)
            return dp[index];

        string currStr = "";
        int minExtra = s.size();
        for (int cutIdx = index; cutIdx < s.size(); cutIdx++)
        {
            currStr.push_back(s[cutIdx]);
            // currStr will be a string from (index to cutIdx)

            // if string not in dictionary, we have to delete as they are extra chars
            int currExtra = (mp.count(currStr)) ? 0 : currStr.size();
            int nextExtra = solve(s, mp, cutIdx + 1, dp);
            int totalExtra = currExtra + nextExtra;

            minExtra = min(minExtra, totalExtra);
        }
        return dp[index] = minExtra;
    }
    int minExtraChar(string s, vector<string> &dictionary)
    {
        unordered_map<string, int> mp;
        vector<int> dp(s.size(), -1);
        for (string &word : dictionary)
            mp[word]++;

        int ans = solve(s, mp, 0, dp);
        return ans;
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        ll n;
        cin >> n;
        vector<string> dictionary(n);
        for (ll i = 0; i < n; i++)
            cin >> dictionary[i];
        Solution ob;
        cout << ob.minExtraChar(s, dictionary) << endl;
        }
    return 0;
}