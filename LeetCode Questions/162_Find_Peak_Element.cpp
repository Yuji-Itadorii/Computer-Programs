// https://leetcode.com/problems/find-peak-element/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    int findPeakElement(vector<int> &arr)
    {
        int n = arr.size();

        if (n == 1)
        {
            return 0;
        }

        int l = 0, r = n - 1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (mid == 0)
            {
                if (arr[mid] > INT_MIN and arr[mid] > arr[mid + 1])
                {
                    return mid;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else if (mid == n - 1)
            {
                if (arr[mid] > INT_MIN and arr[mid] > arr[mid - 1])
                {
                    return mid;
                }
                else
                {
                    r = mid - 1;
                }
            }
            else if (arr[mid] > arr[mid + 1] and arr[mid] > arr[mid - 1])
            {
                return mid;
            }
            else if (arr[mid] < arr[mid - 1])
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return -1;
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

        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.findPeakElement(arr) << endl;
    }
    return 0;
}