// https://practice.geeksforgeeks.org/problems/smaller-on-left20360700/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<int> Smallestonleft(int arr[], int n);

int main()
{

    int t;

    cin >> t;

    while (t--)
    {

        int n;
        cin >> n;
        int arr[n + 1];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        vector<int> b;
        b = Smallestonleft(arr, n);
        for (int i = 0; i < n; i++)
            cout << b[i] << " ";

        cout << endl;
    }

    return 0;
}
// } Driver Code Ends

vector<int> Smallestonleft(int arr[], int n)
{
    // Complete the function
    vector<int> res;
    set<int> s;

    for (int i = 0; i < n; i++)
    {
        auto itr = s.lower_bound(arr[i]);
        if (itr == s.begin())
        {
            res.push_back(-1);
        }
        else
        {
            itr--;
            res.push_back(*itr);
        }

        s.insert(arr[i]);
    }

    return res;
}