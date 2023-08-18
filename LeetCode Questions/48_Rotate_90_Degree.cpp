// https://leetcode.com/problems/rotate-image/submissions/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    void rotate(vector<vector<int>> &arr)
    {

        int n = arr.size();
        int m = arr[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < m; j++)
            {
                swap(arr[i][j], arr[j][i]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            reverse(arr[i].begin(), arr[i].end());
        }
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
        vector<vector<int>> arr(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }
        ob.rotate(arr);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}