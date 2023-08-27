// https://leetcode.com/problems/largest-number/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
private:
    static bool mycomp(int a, int b)
    {
        string comb1 = to_string(a) + to_string(b);
        string comb2 = to_string(b) + to_string(a);
        return comb1 > comb2;
    }

public:
    string largestNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), mycomp);
        if (nums[0] == 0)
            return "0";
        string res = "";
        for (auto num : nums)
        {
            res = res + to_string(num);
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
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        cout << ob.largestNumber(nums) << endl;
    }
    return 0;
}