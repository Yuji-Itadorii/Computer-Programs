// https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{

    bool isValid(int m, vector<int> &arr, int p)
    {
        int count = 0;
        int i = 0;
        while (i < arr.size() - 1)
        {
            if (abs(arr[i] - arr[i + 1]) <= m)
            {
                count++;
                i += 2;
            }
            else
            {
                i++;
            }
        }

        return count >= p;
    }

public:
    int minimizeMax(vector<int> &arr, int p)
    {
        int n = arr.size();

        if (p == 0)
        {
            return 0;
        }

        sort(arr.begin(), arr.end());
        int l = 0, r = 1e9;
        int res = 1e9;
        while (l <= r)
        {
            int mid = (l + r) / 2;

            if (isValid(mid, arr, p))
            {
                res = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
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
        int n, p;
        cin >> n >> p;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << s.minimizeMax(arr, p) << endl;
    }
    return 0;
}