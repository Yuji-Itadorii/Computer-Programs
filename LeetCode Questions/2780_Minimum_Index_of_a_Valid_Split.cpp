// https://leetcode.com/problems/minimum-index-of-a-valid-split/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    int minimumIndex(vector<int> &nums)
    {
        int n = nums.size();

        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }

        int dominant = nums[0];
        for (auto x : mp)
        {
            if (x.second > mp[dominant])
            {
                dominant = x.first;
            }
        }

        vector<int> v(n, 0);
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == dominant)
            {
                count++;
            }
            v[i] = count;
        }

        int ans = -1;
        // cout<<dominant<<endl;
        // for(auto x : v) cout<<x<<" ";

        for (int i = 0; i < n; i++)
        {

            if (v[i] * 2 > i + 1 and (v[n - 1] - v[i]) * 2 > n - 1 - i)
            {
                ans = i;
                break;
            }
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
        Solution s;
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        cout << s.minimumIndex(v) << endl;
    }
    return 0;
}