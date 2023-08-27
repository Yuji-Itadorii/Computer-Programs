// https://leetcode.com/problems/frog-jump/submissions/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{

private:
    unordered_set<int> s;
    map<pair<int, int>, bool> memo;

    bool solve(int i, vector<int> &arr, int k)
    {

        if (s.find(i) == s.end() || i > arr[arr.size() - 1])
        {
            return false;
        }

        if (i == arr[arr.size() - 1])
        {
            return true;
        }

        if (memo.find({i, k}) != memo.end())
            return memo[{i, k}];

        bool isPossible;

        if (i == 0)
        {
            isPossible = solve(i + 1, arr, 1);
        }
        else
        {
            if (k - 1 > 0)
            {
                isPossible = solve(i + (k - 1), arr, k - 1);
            }
            if (isPossible)
                return true;
            isPossible = solve(i + k, arr, k);
            if (isPossible)
                return true;
            isPossible = solve(i + k + 1, arr, k + 1);
            if (isPossible)
                return true;
        }

        return memo[{i, k}] = isPossible;
    }

public:
    bool canCross(vector<int> &stones)
    {
        for (auto itr : stones)
            s.insert(itr);

        return solve(0, stones, 0);
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> stones(n);
        for (int i = 0; i < n; i++)
            cin >> stones[i];
        Solution ob;
        cout << ob.canCross(stones) << endl;
        }
    return 0;
}