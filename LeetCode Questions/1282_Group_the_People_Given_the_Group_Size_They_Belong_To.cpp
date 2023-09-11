// https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/description/?envType=daily-question&envId=2023-09-11

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &arr)
    {
        map<int, vector<int>> mp;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]].push_back(i);
        }

        vector<vector<int>> res;

        for (auto x : mp)
        {
            vector<int> temp = x.second;
            if (temp.size() <= x.first)
            {
                res.push_back(temp);
            }
            else
            {
                int i = 0;
                while (i != temp.size())
                {
                    vector<int> v;
                    int count = 0;
                    while (count < x.first)
                    {
                        v.push_back(temp[i]);
                        i++;
                        count++;
                    }
                    res.push_back(v);
                }
            }
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
        Solution ob;
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<vector<int>> res = ob.groupThePeople(arr);
        for (auto x : res)
        {
            for (auto y : x)
            {
                cout << y << " ";
            }
            cout << endl;
        }
    }
    return 0;
}