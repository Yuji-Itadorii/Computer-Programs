// https://leetcode.com/problems/basic-calculator-ii/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    int calculate(string s)
    {
        stack<int> myStack;
        char sign = '+';
        long long res = 0, tmp = 0;
        for (unsigned int i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]))
                tmp = 10 * tmp + s[i] - '0';
            if (!isdigit(s[i]) && !isspace(s[i]) || i == s.size() - 1)
            {
                if (sign == '-')
                    myStack.push(-tmp);
                else if (sign == '+')
                    myStack.push(tmp);
                else
                {
                    int num;
                    if (sign == '*')
                        num = myStack.top() * tmp;
                    else
                        num = myStack.top() / tmp;
                    myStack.pop();
                    myStack.push(num);
                }
                sign = s[i];
                tmp = 0;
            }
        }
        while (!myStack.empty())
        {
            res += myStack.top();
            myStack.pop();
        }
        return res;
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        Solution s;
        string str;
        cin >> str;
        cout << s.calculate(str) << endl;
    }
    return 0;
}