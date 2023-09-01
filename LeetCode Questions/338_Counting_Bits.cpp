// https://leetcode.com/problems/counting-bits/description/?envType=daily-question&envId=2023-09-01

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans;
        ans.push_back(0);
        for (int i = 1; i <= n; i++)
        {
            int digits = log2(i);
            int range = pow(2, digits);
            ans.push_back(1 + ans[i - range]);
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
        int n;
        cin >> n;
        Solution ob;
        vector<int> ans = ob.countBits(n);
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}