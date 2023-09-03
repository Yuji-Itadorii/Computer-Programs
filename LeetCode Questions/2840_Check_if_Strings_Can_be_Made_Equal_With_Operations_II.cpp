// https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class Solution
{
public:
    bool checkStrings(string s1, string s2)
    {
        vector<char> odd(26, 0), even(26, 0);
        for (int i = 0; i < s1.size(); ++i)
        {
            if (i % 2)
            {
                odd[s1[i] - 'a']++;
                odd[s2[i] - 'a']--;
            }
            else
            {
                even[s1[i] - 'a']++;
                even[s2[i] - 'a']--;
            }
        }
        for (int i = 0; i < odd.size(); ++i)
        {
            if (odd[i] || even[i])
                return false;
        }
        return true;
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;
        cout << ob.checkStrings(s1, s2) << endl;
        }
    return 0;
}