// https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{

    long long mod = 1003;
    unordered_map<string, int> mp;

    long long f(int i, int j, int isTrue, string &exp)
    {
        if (i > j)
            return 0;

        if (i == j)
        {
            if (isTrue)
                return exp[i] == 'T';
            else
                return exp[i] == 'F';
        }

        string temp = to_string(i);
        temp.push_back(' ');
        temp.append(to_string(j));
        temp.push_back(' ');
        temp.append(to_string(isTrue));

        if (mp.find(temp) != mp.end())
            return mp[temp];

        long long ways = 0;
        for (int ind = i + 1; ind <= j - 1; ind += 2)
        {
            long long lT = f(i, ind - 1, 1, exp);
            long long lF = f(i, ind - 1, 0, exp);
            long long rT = f(ind + 1, j, 1, exp);
            long long rF = f(ind + 1, j, 0, exp);

            if (exp[ind] == '&')
            {
                if (isTrue)
                    ways = (ways + (rT * lT) % mod) % mod;
                else
                    ways = (ways + (rT * lF) + (rF * lT) + (rF * lF)) % mod;
            }
            else if (exp[ind] == '|')
            {
                if (isTrue)
                    ways = ((ways + (rT * lT) + (rT * lF) + (rF * lT)) % mod) % mod;
                else
                    ways = (ways + (rF * lF)) % mod;
            }
            else
            {
                if (isTrue)
                    ways = ((ways + (rT * lF) + (rF * lT) % mod)) % mod;
                else
                    ways = (ways + (rF * lF) + (rT * lT)) % mod;
            }
        }

        return mp[temp] = ways;
    }

public:
    int countWays(int N, string S)
    {
        // code here
        return f(0, N - 1, true, S);
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
        string S;
        cin >> S;

        Solution ob;
        cout << ob.countWays(N, S) << "\n";
    }
    return 0;
}
// } Driver Code Ends