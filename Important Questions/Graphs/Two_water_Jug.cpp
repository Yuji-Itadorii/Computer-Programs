// https://practice.geeksforgeeks.org/problems/two-water-jug-problem3402/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int minSteps(int m, int n, int d)
    {
        // Code here
        if (m + n < d)
        {
            return -1;
        }
        int level = 0, newX, newY;
        vector<vector<bool>> vis(m + 1, vector<bool>(n + 1, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0][0] = true;
        while (!q.empty())
        {
            int len = q.size();
            while (len)
            {
                auto node = q.front();
                q.pop();
                // Option 1. Pour jug1 -> jug2
                newX = node.first - min(node.first, n - node.second);
                newY = node.second + min(node.first, n - node.second);
                if (!vis[newX][newY])
                {
                    if (newX == d || newY == d)
                    {
                        return level + 1;
                    }
                    vis[newX][newY] = true;
                    q.push({newX, newY});
                }

                // Option 2. Pour jug2 -> jug1
                newX = node.first + min(m - node.first, node.second);
                newY = node.second - min(m - node.first, node.second);
                if (!vis[newX][newY])
                {
                    if (newX == d || newY == d)
                    {
                        return level + 1;
                    }
                    vis[newX][newY] = true;
                    q.push({newX, newY});
                }

                // Option 3. Fill jug1
                newX = m;
                newY = node.second;
                if (!vis[newX][newY])
                {
                    if (newX == d || newY == d)
                    {
                        return level + 1;
                    }
                    vis[newX][newY] = true;
                    q.push({newX, newY});
                }

                // Option 4. Fill jug2
                newX = node.first;
                newY = n;
                if (!vis[newX][newY])
                {
                    if (newX == d || newY == d)
                    {
                        return level + 1;
                    }
                    vis[newX][newY] = true;
                    q.push({newX, newY});
                }

                // Option 5. Empty jug1
                newX = 0;
                newY = node.second;
                if (!vis[newX][newY])
                {
                    if (newX == d || newY == d)
                    {
                        return level + 1;
                    }
                    vis[newX][newY] = true;
                    q.push({newX, newY});
                }

                // Option 6. Empty jug2
                newX = node.first;
                newY = 0;
                if (!vis[newX][newY])
                {
                    if (newX == d || newY == d)
                    {
                        return level + 1;
                    }
                    vis[newX][newY] = true;
                    q.push({newX, newY});
                }
                len--;
            }
            level++;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m, d;
        cin >> m >> n >> d;
        Solution ob;
        int ans = ob.minSteps(m, n, d);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends