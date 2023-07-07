// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.

    static bool mycomp(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.second < b.second)
            return true;
        if (a.second > b.second)
            return false;
        return a.first < b.first;
    }

    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int, int>> p;

        for (int i = 0; i < n; i++)
        {
            p.push_back({start[i], end[i]});
        }

        sort(p.begin(), p.end(), mycomp);
        int count = 1;

        int prev = 0;
        for (int i = 1; i < n; i++)
        {
            if (p[i].first > p[prev].second)
            {
                count++;
                prev = i;
            }
        }

        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends