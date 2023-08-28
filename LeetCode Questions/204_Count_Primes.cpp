// https://leetcode.com/problems/count-primes/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{

private:
public:
    int countPrimes(int n)
    {
        int count = 0;
        vector<int> vis(n, false);

        for (int i = 2; i < n; i++)
        {
            if (vis[i])
            {
                continue;
            }
            count++;
            for (int j = 2; i * j < n; j++)
            {
                vis[i * j] = true;
            }
        }

        return count;
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
        cout << s.countPrimes(n) << endl;
    }
    return 0;
}