// https://leetcode.com/problems/maximum-profit-in-job-scheduling/submissions/915202410/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool comp(vector<int> a, vector<int> b)
    {
        return a[1] < b[1];
    }

    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        vector<vector<int>> v;
        int n = startTime.size();
        for (int i = 0; i < n; i++)
        {
            int x = startTime[i];
            int y = endTime[i];
            int z = profit[i];
            v.push_back({x, y, z});
        }

        sort(v.begin(), v.end(), comp);

        vector<int> dp(n, 0);
        dp[0] = v[0][2];

        for (int i = 1; i < n; i++)
        {
            int inclu = v[i][2];
            int low = 0, high = i - 1;
            int last = -1;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (v[mid][1] <= v[i][0])
                {
                    last = mid;
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }

            if (last != -1)
            {
                inclu += dp[last];
            }

            int exclu = dp[i - 1];
            dp[i] = max(inclu, exclu);
        }

        return dp[n - 1];
    }
};

int main()
{

    return 0;
}