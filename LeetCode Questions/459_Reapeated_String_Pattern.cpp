#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        string doubled = s + s;
        string sub = doubled.substr(1, doubled.size() - 2);
        return sub.find(s) != string::npos;
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        Solution ob;
        string s;
        cin >> s;
        cout << ob.repeatedSubstringPattern(s) << endl;
    }
    return 0;
}