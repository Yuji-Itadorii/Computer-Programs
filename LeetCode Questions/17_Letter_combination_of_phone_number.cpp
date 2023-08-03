// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    map<char, string> m;

    void solve(int itr, vector<string> &res, string &digits, string s)
    {
        if (itr == digits.size())
        {
            res.push_back(s);
            return;
        }

        for (int j = 0; j < m[digits[itr]].size(); j++)
        {
            s.push_back(m[digits[itr]][j]);
            solve(itr + 1, res, digits, s);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {

        if (digits.size() == 0)
        {
            return {};
        }

        char c = 'a';
        for (char i = '2'; i <= '9'; i++)
        {
            string temp = "";
            for (int j = 0; j < 3; j++)
            {
                temp += string(1, c);
                c++;
            }

            if (i == '7' || i == '9')
            {
                temp += string(1, c);
                c++;
            }
            m[i] = temp;
        }
        vector<string> res;

        solve(0, res, digits, "");

        return res;
    }
};

int main()
{
    Solution s;
    vector<string> res = s.letterCombinations("23");

    for (auto i : res)
    {
        cout << i << " ";
    }

        return 0;
}