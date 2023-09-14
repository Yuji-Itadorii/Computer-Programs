// https://leetcode.com/problems/candy/?envType=daily-question&envId=2023-09-13

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        if (n <= 1)
        {
            return n;
        }

        vector<int> c(n, 1);

        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                c[i] = c[i - 1] + 1;
            }
        }

        for (int i = n - 1; i > 0; i--)
        {
            if (ratings[i - 1] > ratings[i])
            {
                c[i - 1] = max(c[i] + 1, c[i - 1]);
            }
        }

        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += c[i];

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
        vector<int> ratings = {1, 0, 2};
        cout << ob.candy(ratings) << endl;
        }
    return 0;
}