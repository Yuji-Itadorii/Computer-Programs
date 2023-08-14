// https://practice.geeksforgeeks.org/problems/knight-walk4521/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int n)
    {
        // Code here
        int X[8] = {1, 2, 2, 1, -1, -2, -2, -1};
        int Y[8] = {2, 1, -1, -2, -2, -1, 1, 2};

        queue<pair<int, int>> q;
        q.push({KnightPos[0], KnightPos[1]});

        vector<vector<int>> vis(n + 1, vector<int>(n + 1, 0));
        vector<vector<int>> dis(n + 1, vector<int>(n + 1, 0));
        vis[KnightPos[0]][KnightPos[1]] = 1;

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            int x = it.first, y = it.second;

            if (x == TargetPos[0] && y == TargetPos[1])
                return dis[x][y];

            for (int i = 0; i < 8; i++)
            {
                int nx = x + X[i];
                int ny = y + Y[i];

                if (nx < 1 || nx > n || ny < 1 || ny > n)
                {
                    continue;
                }
                else
                {
                    if (vis[nx][ny] == 0)
                    {
                        vis[nx][ny] = 1;
                        dis[nx][ny] = dis[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
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
        vector<int> KnightPos(2);
        vector<int> TargetPos(2);
        int N;
        cin >> N;
        cin >> KnightPos[0] >> KnightPos[1];
        cin >> TargetPos[0] >> TargetPos[1];
        Solution obj;
        int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends