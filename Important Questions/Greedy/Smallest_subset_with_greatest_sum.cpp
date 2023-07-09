// https://practice.geeksforgeeks.org/problems/smallest-subset-with-greater-sum/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int minSubset(vector<int> &arr, int n)
    {
        sort(arr.begin(), arr.end(), greater<int>());

        long long int totalSum = 0;
        for (int i = 0; i < n; i++)
        {
            totalSum += arr[i];
        }

        int count = 0;

        long long int tempSum = 0;

        for (int i = 0; i < n; i++)
        {
            if (tempSum > totalSum)
            {
                break;
            }
            else
            {
                tempSum += arr[i];
                totalSum -= arr[i];
                count++;
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
        int N;
        cin >> N;
        vector<int> Arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> Arr[i];
        }
        Solution ob;
        cout << ob.minSubset(Arr, N) << endl;
    }
    return 0;
}
// } Driver Code Ends