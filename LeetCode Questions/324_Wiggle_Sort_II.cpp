// https://leetcode.com/problems/wiggle-sort-ii/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 1, j = n - 1;
        vector<int> res(n);
        while (i < n)
        {
            res[i] = nums[j];
            i += 2;
            j--;
        }

        i = 0;
        while (i < n)
        {
            res[i] = nums[j];
            i += 2;
            j--;
        }

        for (int k = 0; k < n; k++)
        {
            nums[k] = res[k];
        }
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        Solution s;
        vector<int> nums;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            nums.push_back(x);
        }
        s.wiggleSort(nums);
        for (int i = 0; i < n; i++)
        {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
    return 0;
}