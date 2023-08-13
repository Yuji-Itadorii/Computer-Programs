// https://leetcode.com/problems/maximum-length-of-pair-chain/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

#include <bits/stdc++.h>

class Solution
{
private:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1] || a[1] == b[1] && a[0] < b[0];
    }

public:
    int findLongestChain(vector<vector<int>> &arr)
    {
        sort(arr.begin(), arr.end(), cmp);

        int count = 1;
        int prev = 0;
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[prev][1] < arr[i][0])
            {
                count++;
                prev = i;
            }
        }

        return count;
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
        vector<vector<int>> arr(n, vector<int>(2));
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i][0] >> arr[i][1];
        }
        Solution s;
        cout << s.findLongestChain(arr) << endl;
    }
    return 0;
}