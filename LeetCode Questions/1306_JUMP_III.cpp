// https://leetcode.com/problems/jump-game-iii/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    bool canReach(vector<int> &arr, int start)
    {
        if (arr[start] == -1)
            return false;

        if (!arr[start])
            return true;

        int leftside = start - arr[start], rightside = start + arr[start];

        arr[start] = -1;
        return rightside = (rightside < arr.size() && canReach(arr, rightside)) || (leftside >= 0 && canReach(arr, leftside));
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int start;
        cin >> start;
        cout << ob.canReach(arr, start) << endl;
    }
    return 0;
}