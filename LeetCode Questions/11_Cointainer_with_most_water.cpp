// https://leetcode.com/problems/container-with-most-water/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int water = 0;
        int i = 0, j = height.size() - 1;
        while (i < j)
        {
            int h = min(height[i], height[j]);
            water = max(water, (j - i) * h);
            while (height[i] <= h && i < j)
                i++;
            while (height[j] <= h && i < j)
                j--;
        }
        return water;
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
        vector<int> height(n);
        for (int i = 0; i < n; i++)
        {
            cin >> height[i];
        }
        cout << ob.maxArea(height) << endl;
    }
    return 0;
}