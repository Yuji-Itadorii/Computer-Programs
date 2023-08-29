// https://leetcode.com/problems/minimum-penalty-for-a-shop/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    int bestClosingTime(string s)
    {
        int n = s.size();
        int ind = -1, mxscore = 0, score = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'Y')
                score++;
            else
                score--;
            if (score > mxscore)
            {
                mxscore = score;
                ind = i;
            }
        }
        return ind + 1;
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
        cout << ob.bestClosingTime(s) << endl;
    }
    return 0;
}
