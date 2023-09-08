// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    int longestSubstring(string s, int k)
    {
        int n = (int)s.length();
        unordered_map<char, int> count;
        for (char c : s)
            ++count[c];
        int mid = 0;
        while (mid < n && count[s[mid]] >= k)
            ++mid;
        if (mid == n)
            return n;
        int left = longestSubstring(s.substr(0, mid), k);
        while (mid < n && count[s[mid]] < k)
            ++mid;
        int right = longestSubstring(s.substr(mid), k);
        return max(left, right);
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
        int k;
        cin >> k;
        cout << s.longestSubstring(str, k) << endl;
    }
    return 0;
}