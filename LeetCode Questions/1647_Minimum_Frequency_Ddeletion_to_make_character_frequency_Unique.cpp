// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/description/?envType=daily-question&envId=2023-09-12

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    int minDeletions(string s)
    {
        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;
        sort(freq.begin(), freq.end());
        int del = 0;
        for (int i = 24; i >= 0; i--)
        {
            if (freq[i] == 0)
                break;
            if (freq[i] >= freq[i + 1])
            {
                int prev = freq[i];
                freq[i] = max(0, freq[i + 1] - 1);
                del += prev - freq[i];
            }
        }
        return del;
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
        cout << ob.minDeletions(s) << endl;
    }
    return 0;
}