// https://leetcode.com/problems/combinations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(int n, int k, int i, vector<vector<int>> &ans, vector<int> &temp)
    {

        if (temp.size() == k)
        {
            ans.push_back(temp);
            return;
        }

        for (int cnt = i; cnt <= n; cnt++)
        {
            temp.push_back(cnt);
            solve(n, k, cnt + 1, ans, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;

        vector<int> temp;

        solve(n, k, 1, ans, temp);

        return ans;
    }
};

int main()
{

    return 0;
}