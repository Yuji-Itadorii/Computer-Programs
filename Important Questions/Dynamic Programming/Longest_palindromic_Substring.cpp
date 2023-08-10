// https://leetcode.com/problems/longest-palindromic-substring/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{

public:
    string ans = "";
    void expand(string &s, int left, int right)
    {
        while (left >= 0 && right < s.size())
        {
            if (s[left] != s[right])
                break;
            left--, right++;
        }
        if (ans.size() < right - left)
            ans = s.substr(left + 1, right - left - 1);
    }
    string longestPalindrome(string s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            expand(s, i, i);
            expand(s, i, i + 1);
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
        cout << ob.longestPalindrome(s) << endl;
    }
    return 0;
}