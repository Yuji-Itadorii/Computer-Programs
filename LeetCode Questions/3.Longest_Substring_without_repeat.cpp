// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> set;

        int i = 0;
        int j = 0;
        int n = s.size();
        int ans = 0;

        while (i < n and j < n)
        {
            if (set.find(s[j]) == set.end())
            {
                set.insert(s[j++]);
                ans = max(ans, j - i);
            }
            else
            {
                set.erase(s[i++]);
            }
        }

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

        Solution ob;
        cout << ob.lengthOfLongestSubstring(s) << endl;
    }
    return 0;
}