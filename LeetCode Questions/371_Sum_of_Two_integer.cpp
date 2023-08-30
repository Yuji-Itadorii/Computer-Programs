// https://leetcode.com/problems/sum-of-two-integers/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    int getSum(int a, int b)
    {
        int sum = 0, c = 0; // 'c' represents our carry bit
        int x = 0, y = 0;
        for (int i = 0; i < 32; i++)
        {
            x = 1 & a;
            a = a >> 1;
            y = 1 & b;
            b = b >> 1;
            sum = sum | (((x ^ y) ^ c) << i);
            c = (x & y | y & c | c & x);
        }
        return sum;
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        Solution ob;
        int a, b;
        cin >> a >> b;
        cout << ob.getSum(a, b) << endl;
        }
    return 0;
}