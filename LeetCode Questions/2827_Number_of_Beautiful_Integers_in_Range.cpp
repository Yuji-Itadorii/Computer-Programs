// https://leetcode.com/problems/number-of-beautiful-integers-in-the-range/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
private:
    int dp[2][12][12][12][20][2];
    int k;

    int solve(string &s, int tight = 1, int pos = 0, int odd = 0, int even = 0, int sum = 0, bool zero = true)
    {
        if (pos == s.size())
            return !zero && sum == 0 && odd == even;

        if (dp[tight][pos][odd][even][sum][zero] != -1)
            return dp[tight][pos][odd][even][sum][zero];

        int start = 0;
        int end = (tight ? s[pos] - '0' : 9);
        int ans = (zero ? solve(s, 0, pos + 1, odd, even, sum, zero) : 0);

        for (int i = start; i <= end; i++)
        {
            int newTight = (tight && (i == s[pos] - '0'));
            int newOdd = odd + (i % 2);
            int newEven = even + ((!zero || i > 0) && i % 2 == 0);

            if (zero && i != 0)
            {
                ans += solve(s, newTight, pos + 1, newOdd, newEven, i, false);
            }
            else if (!zero)
            {
                ans += solve(s, newTight, pos + 1, newOdd, newEven, (sum * 10 + i) % k, false);
            }
        }

        return dp[tight][pos][odd][even][sum][zero] = ans;
    }

public:
    int numberOfBeautifulIntegers(int low, int high, int k)
    {
        string s_low = to_string(low - 1);
        string s_high = to_string(high);
        this->k = k;

        memset(dp, -1, sizeof(dp));
        int maxi = solve(s_high);

        memset(dp, -1, sizeof(dp));
        int mini = solve(s_low);

        return maxi - mini;
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        Solution ob;
        int low, high, k;
        cin >> low >> high >> k;
        cout << ob.numberOfBeautifulIntegers(low, high, k) << endl;
        }
    return 0;
}