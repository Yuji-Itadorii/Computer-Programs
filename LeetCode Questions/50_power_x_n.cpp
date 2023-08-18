// https://leetcode.com/problems/powx-n/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n < 0)
        {
            x = 1 / x;
        }

        long num = abs(n);

        double pow = 1;

        while (num)
        { // equivalent to while(num != 0)
            if (num & 1)
            { // equivalent to if((num & 1) != 0)
                pow *= x;
            }

            x *= x;
            num >>= 1;
        }

        return pow;
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        Solution ob;
        double x;
        int n;
        cin >> x >> n;
        cout << ob.myPow(x, n) << endl;
    }
    return 0;
}