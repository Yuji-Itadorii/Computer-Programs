// https://leetcode.com/problems/remove-invalid-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isValid(string s)
    {
        int sum = 0;
        for (char &c : s)
        {
            if (c == '(')
                ++sum;
            else if (c == ')')
                --sum;
            if (sum < 0)
                return false;
        }
        return sum == 0;
    }

    void dfs(string s, int beg, int num1, int num2, vector<string> &ret)
    {
        if (num1 == 0 && num2 == 0)
        {
            if (isValid(s))
                ret.push_back(s);
        }
        else
        {
            for (int i = beg; i < s.size(); ++i)
            {
                string tmp = s;
                if (num1 > 0 && tmp[i] == '(')
                {
                    if (i == beg || tmp[i] != tmp[i - 1])
                    {
                        tmp.erase(i, 1);
                        dfs(tmp, i, num1 - 1, num2, ret);
                    }
                }
                if (num2 > 0 && tmp[i] == ')')
                {
                    if (i == beg || tmp[i] != tmp[i - 1])
                    {
                        tmp.erase(i, 1);
                        dfs(tmp, i, num1, num2 - 1, ret);
                    }
                }
            }
        }
    }

public:
    vector<string> removeInvalidParentheses(string s)
    {
        int num1 = 0, num2 = 0;
        for (char &c : s)
        {
            if (c == '(')
            {
                num1++;
            }
            if (num1 == 0)
            {
                if (c == ')')
                {
                    num2++;
                }
            }
            else
            {
                if (c == ')')
                {
                    num1--;
                }
            }
        }
        vector<string> ret;
        dfs(s, 0, num1, num2, ret);
        return ret;
    }
};

int main()
{
    Solution s;
    string str = "()())()";
    vector<string> ret = s.removeInvalidParentheses(str);
    for (string &s : ret)
    {
        cout << s << endl;
    }
    return 0;
}