// https://leetcode.com/problems/reverse-integer/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    int reverse(int x)
    {
        long r = 0;
        while (x)
        {
            r = r * 10 + x % 10;
            x = x / 10;
        }
        if (r > INT_MAX || r < INT_MIN)
            return 0;
        return int(r);
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        Solution s;
        int n;
        cin >> n;
        cout << s.reverse(n) << endl;
    }
    return 0;
}