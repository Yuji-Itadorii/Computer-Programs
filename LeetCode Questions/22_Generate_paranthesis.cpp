// https://leetcode.com/problems/generate-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{

private:
    void solve(vector<string> &v, string str, int n, int m)
    {
        if (n == 0 && m == 0)
        {
            v.push_back(str);
            return;
        }
        if (m > 0)
        {
            solve(v, str + ")", n, m - 1);
        }
        if (n > 0)
        {
            solve(v, str + "(", n - 1, m + 1);
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        solve(res, "", n, 0);
        return res;
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        Solution ob;
        int n;
        cin >> n;
        vector<string> ans = ob.generateParenthesis(n);
        for (auto i : ans)
        {
            cout << i << endl;
        }

        cout << endl;
    }
    return 0;
}