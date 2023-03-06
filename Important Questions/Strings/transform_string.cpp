// https://practice.geeksforgeeks.org/problems/transform-string5648/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int transform(string A, string B)
    {
        // code here.
        int i = A.size() - 1, j = B.size() - 1;
        if (i != j)
        {
            return -1;
        }

        unordered_map<char, int> m;
        for (int k = 0; k < A.size(); k++)
        {
            m[A[k]]++;
            m[B[k]]--;
        }

        for (auto x : m)
        {
            if (x.second != 0)
            {
                return -1;
            }
        }
        int res = 0;
        while (i >= 0 && j >= 0)
        {
            if (A[i] == B[j])
            {
                i--;
                j--;
            }
            else
            {
                res++;
                i--;
            }
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
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.transform(A, B) << endl;
    }
}
// } Driver Code Ends