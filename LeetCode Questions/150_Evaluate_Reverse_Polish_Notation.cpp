// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{

private:
    bool check(string &s)
    {
        if (s == "+" || s == "-" || s == "*" || s == "/")
        {
            return true;
        }
        return false;
    }

    int solve(int a, int b, string &op)
    {
        if (op == "+")
        {
            return a + b;
        }
        else if (op == "-")
        {
            return a - b;
        }
        else if (op == "*")
        {
            return a * b;
        }
        else
        {
            return a / b;
        }
    }

public:
    int evalRPN(vector<string> &tokens)
    {
        stack<string> st;

        int n = tokens.size();

        for (int i = 0; i < n; i++)
        {
            if (check(tokens[i]) == false)
            {
                st.push(tokens[i]);
            }
            else
            {
                string a = st.top();
                st.pop();
                string b = st.top();
                st.pop();
                int x = stoi(a);
                int y = stoi(b);
                int res = solve(y, x, tokens[i]);
                st.push(to_string(res));
            }
        }

        return stoi(st.top());
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        Solution s;
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        cout << s.evalRPN(v) << endl;
    }
    return 0;
}