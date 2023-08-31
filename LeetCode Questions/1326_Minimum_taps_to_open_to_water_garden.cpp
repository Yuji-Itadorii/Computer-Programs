// https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    int minTaps(int n, vector<int> &ranges)
    {

        vector<vector<int>> intervals;
        for (int i = 0; i < ranges.size(); i++)
        {
            vector<int> inter{i - ranges[i], i + ranges[i]};
            // for(auto x : inter) cout<<x<<" ";
            intervals.push_back(inter);
        }

        sort(intervals.begin(), intervals.end(), [](auto &p, auto &q)
             { return (p[0] < q[0]); });

        int count = 0, start_time = 0, end_time = 0, i = 0;

        while (end_time < n)
        {
            for (; i < intervals.size() && intervals[i][0] <= start_time; i++)
            {
                end_time = max(end_time, intervals[i][1]);
                // cout<<start_time<<" "<<end_time<<endl;
            }
            // cout<<endl;
            if (start_time == end_time)
                return -1;
            start_time = end_time;
            count++;
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
        Solution ob;
        int n;
        cin >> n;
        vector<int> ranges(n);
        for (int i = 0; i < n; i++)
            cin >> ranges[i];
        cout << ob.minTaps(n, ranges) << endl;
    }
    return 0;
}