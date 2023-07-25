// https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums)
    {
        // Code here.
        int temp = 0;
        for (auto it : nums)
            temp ^= it;

        int firstSet = 0;

        while (temp)
        {
            if (temp & 1)
            {
                break;
            }
            temp = temp >> 1;
            firstSet++;
        }

        int set = 0, unset = 0;
        for (auto it : nums)
        {

            if (it >> firstSet & 1)
            {
                set ^= it;
            }
            else
            {
                unset ^= it;
            }
        }

        return {min(set, unset), max(set, unset)};
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> v(2 * n + 2);
        for (int i = 0; i < 2 * n + 2; i++)
            cin >> v[i];
        Solution ob;
        vector<int> ans = ob.singleNumber(v);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends