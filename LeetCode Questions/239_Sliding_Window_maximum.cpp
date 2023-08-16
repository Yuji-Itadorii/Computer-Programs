#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        priority_queue<pair<int, int>> pq;
        int n = nums.size();

        for (int i = 0; i < k; i++)
        {
            pq.push({nums[i], i});
        }

        vector<int> res;
        res.push_back(pq.top().first);

        for (int i = k; i < n; i++)
        {
            while (pq.top().second < i - k + 1 and pq.empty() == false)
            {
                pq.pop();
            }

            pq.push({nums[i], i});

            res.push_back(pq.top().first);
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
        Solution ob;
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        vector<int> res = ob.maxSlidingWindow(nums, k);
        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i] << " ";
        }
        cout << endl;
    }
    return 0;
}