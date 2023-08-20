// https://leetcode.com/problems/jump-game-iv/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{

public:
    int minJumps(vector<int> &arr)
    {

        int n = arr.size();
        unordered_map<int, vector<int>> indices;
        for (int i = 0; i < n; i++)
        {
            indices[arr[i]].push_back(i);
        }

        vector<int> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int steps = 0;

        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                int curr = q.front();
                q.pop();

                if (curr == n - 1)
                {
                    return steps;
                }

                if (curr - 1 >= 0 && !visited[curr - 1])
                {
                    q.push(curr - 1);
                    visited[curr - 1] = true;
                }

                if (curr + 1 < n && !visited[curr + 1])
                {
                    q.push(curr + 1);
                    visited[curr + 1] = true;
                }

                for (int idx : indices[arr[curr]])
                {
                    if (idx != curr && !visited[idx])
                    {
                        q.push(idx);
                        visited[idx] = true;
                    }
                }

                indices[arr[curr]].clear();
            }
            steps++;
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
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution ob;
        cout << ob.minJumps(arr) << endl;
    }
    return 0;
}