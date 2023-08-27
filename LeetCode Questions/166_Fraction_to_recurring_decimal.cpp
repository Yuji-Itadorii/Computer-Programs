// https://leetcode.com/problems/fraction-to-recurring-decimal/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        if (!numerator)
        {
            return "0";
        }
        string ans;
        if (numerator > 0 ^ denominator > 0)
        {
            ans += '-';
        }
        long n = labs(numerator), d = labs(denominator), r = n % d;
        ans += to_string(n / d);
        if (!r)
        {
            return ans;
        }
        ans += '.';
        unordered_map<long, int> rs;
        while (r)
        {
            if (rs.find(r) != rs.end())
            {
                ans.insert(rs[r], "(");
                ans += ')';
                break;
            }
            rs[r] = ans.size();
            r *= 10;
            ans += to_string(r / d);
            r %= d;
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
        Solution ob;
        int a, b;
        cin >> a >> b;
        cout << ob.fractionToDecimal(a, b) << endl;
    }
    return 0;
}