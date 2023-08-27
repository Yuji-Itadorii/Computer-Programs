// https://leetcode.com/problems/factorial-trailing-zeroes/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    int trailingZeroes(int n)
    {
        int res = 0;
        while (n)
        {
            res += n / 5;
            n = n / 5;
        }

        return res;
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
        cout << s.trailingZeroes(n) << endl;
    }
    return 0;
}