// https://leetcode.com/problems/excel-sheet-column-title/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string ans;
        while (columnNumber > 0)
        {
            columnNumber--;
            int curr = columnNumber % 26;
            columnNumber = columnNumber / 26;
            ans.push_back(curr + 'A');
        }
        reverse(ans.begin(), ans.end());
        return ans;
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
        Solution ob;
        cout << ob.convertToTitle(n) << endl;
    }
    return 0;
}