// https://leetcode.com/problems/shuffle-an-array/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
    vector<int> nums;

public:
    Solution(vector<int> nums)
    {
        this->nums = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        return nums;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        vector<int> result(nums);
        for (int i = 0; i < result.size(); i++)
        {
            int pos = rand() % (result.size() - i);
            swap(result[i + pos], result[i]);
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            nums.push_back(x);
        }
        Solution *obj = new Solution(nums);

        vector<int> param_1 = obj->reset();
        vector<int> param_2 = obj->shuffle();

        for (int i = 0; i < param_1.size(); i++)
        {
            cout << param_1[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < param_2.size(); i++)
        {
            cout << param_2[i] << " ";
        }
        cout << endl;
    }
    return 0;
}