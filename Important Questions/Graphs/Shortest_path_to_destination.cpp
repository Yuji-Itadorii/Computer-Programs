// https://practice.geeksforgeeks.org/problems/shortest-source-to-destination-path3544/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int shortestDistance(int N, int M, vector<vector<int>> arr, int X, int Y)
    {
        // code here

        if (arr[0][0] == 0)
        {
            return -1;
        }

        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<vector<int>> vis(N, vector<int>(M, 0));
        vis[0][0] = 1;

        int x[] = {0, 1, 0, -1};
        int y[] = {1, 0, -1, 0};

        while (!q.empty())
        {

            auto it = q.front();
            q.pop();
            int i = it.first;
            int j = it.second;

            for (int k = 0; k < 4; k++)
            {
                int nx = i + x[k];
                int ny = j + y[k];

                if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                {
                    continue;
                }

                if (vis[nx][ny] == 0 and arr[nx][ny] == 1)
                {
                    q.push({nx, ny});
                    vis[nx][ny] = vis[i][j] + 1;
                }
            }
        }

        if (vis[X][Y] == 0)
        {
            return -1;
        }
        else
        {
            return vis[X][Y] - 1;
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends