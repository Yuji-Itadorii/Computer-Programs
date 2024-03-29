// https://leetcode.com/problems/string-to-integer-atoi/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    int myAtoi(string str)
    {
        int sign = 1, base = 0, i = 0;
        while (str[i] == ' ')
        {
            i++;
        }
        if (str[i] == '-' || str[i] == '+')
        {
            sign = 1 - 2 * (str[i++] == '-');
        }

        while (str[i] >= '0' && str[i] <= '9')
        {
            if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7))
            {
                if (sign == 1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }
            base = 10 * base + (str[i++] - '0');
        }

        return base * sign;
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
        cout << ob.myAtoi(s) << endl;
    }
    return 0;
}