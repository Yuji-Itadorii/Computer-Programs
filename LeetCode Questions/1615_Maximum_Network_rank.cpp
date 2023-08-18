// https://leetcode.com/problems/maximal-network-rank/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads)
    {
        vector<set<int>> adj(n);

        for (auto it : roads)
        {
            adj[it[0]].insert(it[1]);
            adj[it[1]].insert(it[0]);
        }

        int ans = INT_MIN;
        // - adj[i].find(i+1) == adj[i].end()? 0 : 1

        // cout<<;

        // cout<<*adj[2].find(3) <<endl;

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int nr = adj[i].size() + adj[j].size() - ((adj[i].find(j) != adj[i].end()) ? 1 : 0);
                ans = max(ans, nr);
            }
        }

        return ans;
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> roads(m, vector<int>(2));

        for (int i = 0; i < m; i++)
        {
            cin >> roads[i][0] >> roads[i][1];
        }

        Solution ob;
        cout << ob.maximalNetworkRank(n, roads) << endl;
    }
    return 0;
}
