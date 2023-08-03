// https://medium.com/@srinjoy_ray/demystifying-dynamic-programming-8bf4204f18ca

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        ll dp[n + 1];
        memset(dp, 0, sizeof dp);

        ll mod = 1e9 + 7;

        dp[1] = 2;

        ll half = 1, full = 1;

        for (int i = 2; i <= n; i++)
        {

            ll new_half, new_full;

            new_full = (2 * full + half) % mod;
            new_half = (full + 4 * half) % mod;

            dp[i] = (new_full + new_half) % mod;

            full = new_full;
            half = new_half;
        }

        cout << dp[n] << endl;
    }

    return 0;
}