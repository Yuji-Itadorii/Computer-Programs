// https://leetcode.com/problems/sort-colors/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int i = 0, j = 0, k = nums.size() - 1;
        while (i <= k and j <= k)
        {
            if (nums[j] == 0)
            {
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
            else if (nums[j] == 1)
            {
                j++;
            }
            else
            {
                swap(nums[j], nums[k]);
                k--;
            }
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
        int n;
        cin >> n;
        vector<int> nums(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        s.sortColors(nums);
        for (int i = 0; i < n; i++)
        {
            cout << nums[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}