//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    string longestPalindrome(string s)
    {
        // code here
        string res = "";
        int len = 0;
        int a = 0, b = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int l = i, r = i;
            while (l >= 0 and r < s.size() and s[l] == s[r])
            {
                if (r - l + 1 > len)
                {
                    len = r - l + 1;
                    a = l, b = r;
                }
                l--;
                r++;
            }

            l = i;
            r = i + 1;
            while (l >= 0 and r < s.size() and s[l] == s[r])
            {
                if (r - l + 1 > len)
                {
                    len = r - l + 1;
                    a = l, b = r;
                }
                l--;
                r++;
            }
        }

        for (int i = a; i <= b; i++)
        {
            res += s[i];
        }

        return res;
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
        cout << ob.longestPalindrome(S) << endl;
    }
    return 0;
}

// } Driver Code Ends