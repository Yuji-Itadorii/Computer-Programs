// https://practice.geeksforgeeks.org/problems/valid-substring0624/1

//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for c++
class Solution
{
public:
    int solve(string &str, int n)
    {
        int left = 0, right = 0, ans = 0;

        for (int i = 0; i < n; i++)
        {

            if (str[i] == '(')
            {
                left++;
            }
            else if (str[i] == ')')
            {
                right++;
            }

            if (left == right)
                ans = max(ans, 2 * right);
            else if (right > left)
                left = right = 0;
        }

        left = 0, right = 0;
        for (int i = n - 1; i >= 0; i--)
        {

            if (str[i] == '(')
            {
                left++;
            }
            else if (str[i] == ')')
            {
                right++;
            }

            if (left == right)
                ans = max(ans, 2 * right);
            else if (left > right)
                left = right = 0;
        }

        return ans;
    }

    int findMaxLen(string s)
    {
        // code here
        int n = s.size();
        return solve(s, n);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends