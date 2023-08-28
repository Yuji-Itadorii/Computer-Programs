// https://leetcode.com/problems/minimum-operations-to-form-subsequence-with-target-sum/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    int minOperations(vector<int> &A, int target)
    {
        long long tot = accumulate(A.begin(), A.end(), 0L), res = 0;
        if (tot < target)
            return -1;
        sort(A.begin(), A.end());
        while (target > 0)
        {
            int a = A.back();
            A.pop_back();
            if (tot - a >= target)
            {
                tot -= a;
            }
            else if (a <= target)
            {
                tot -= a;
                target -= a;
            }
            else
            {
                A.push_back(a / 2);
                A.push_back(a / 2);
                res += 1;
            }
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
        vector<int> A;
        int n, target;
        cin >> n >> target;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            A.push_back(x);
        }
        cout << s.minOperations(A, target) << endl;
    }
    return 0;
}