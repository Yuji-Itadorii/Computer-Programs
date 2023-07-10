// https://practice.geeksforgeeks.org/problems/smallest-number5829/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string smallestNumber(int sum, int digit)
    {
        // code here
        if (sum > digit * 9)
            return "-1";

        vector<int> res(digit, 0);

        int i = digit - 1;

        while (sum > 9)
        {
            res[i] = 9;

            i--;

            sum -= 9;
        }

        if (i == 0)
        {
            res[0] = sum;
        }

        else if (i > 0)
        {
            res[0] = 1;

            res[i] = sum - 1;
        }

        string ans = "";

        for (int i = 0; i < res.size(); i++)
        {
            ans += to_string(res[i]);
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int S, D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S, D) << endl;
    }
    return 0;
}
// } Driver Code Ends