// https://practice.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to insert heap.

    priority_queue<double> s;
    priority_queue<double, vector<double>, greater<double>> g;

    void insertHeap(int &x)
    {
        if (s.size() == 0 || s.top() > x)
        {
            s.push(x);
        }
        else
        {
            g.push(x);
        }

        balanceHeaps();
    }

    // Function to balance heaps.
    void balanceHeaps()
    {
        if (s.size() > g.size() + 1)
        {
            g.push(s.top());
            s.pop();
        }
        else if (g.size() > s.size())
        {
            s.push(g.top());
            g.pop();
        }
    }

    // Function to return Median.
    double getMedian()
    {
        double med;
        if (g.size() == s.size())
        {
            med = (s.top() + g.top()) / 2.0;
        }
        else
        {
            med = s.top();
        }
        return med;
    }
};

//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin >> t;
    while (t--)
    {
        Solution ob;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> x;
            ob.insertHeap(x);
            cout << floor(ob.getMedian()) << endl;
        }
    }
    return 0;
}
// } Driver Code Ends