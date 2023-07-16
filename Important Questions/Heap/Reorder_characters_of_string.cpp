// https://practice.geeksforgeeks.org/problems/rearrange-characters4649/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

// } Driver Code Ends
class Solution
{
public:
    string rearrangeString(string str)
    {
        // code here
        unordered_map<char, int> mp;
        int n = str.size();
        for (int i = 0; i < n; i++)
        {
            mp[str[i]]++;
        }

        priority_queue<pair<int, char>> pq;

        for (int i = 'a'; i <= 'z'; i++)
        {
            if (mp[i] > 0)
            {
                pq.push({mp[i], i});
            }

            if (mp[i] > (str.size() + 1) / 2)
                return "-1";
        }

        string res = "";

        while (pq.size() >= 2)
        {
            pair<int, char> a = pq.top();
            pq.pop();

            pair<int, char> b = pq.top();
            pq.pop();

            res += a.second;
            res += b.second;

            if (a.first - 1 > 0)
            {
                pq.push({a.first - 1, a.second});
            }

            if (b.first - 1 > 0)
            {
                pq.push({b.first - 1, b.second});
            }
        }

        while (!pq.empty())
        {
            res += pq.top().second;
            pq.pop();
        }

        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution ob;
        string str1 = ob.rearrangeString(str);
        int flag = 1;
        int c[26] = {0};
        for (int i = 0; i < str.length(); i++)
            c[str[i] - 'a'] += 1;
        int f = 0;
        int x = (str.length() + 1) / 2;
        for (int i = 0; i < 26; i++)
        {
            if (c[i] > x)
                f = 1;
        }
        if (f)
        {
            if (str1 == "-1")
                cout << 0 << endl;
            else
                cout << 1 << endl;
        }
        else
        {
            int a[26] = {0};
            int b[26] = {0};
            for (int i = 0; i < str.length(); i++)
                a[str[i] - 'a'] += 1;
            for (int i = 0; i < str1.length(); i++)
                b[str1[i] - 'a'] += 1;

            for (int i = 0; i < 26; i++)
                if (a[i] != b[i])
                    flag = 0;

            for (int i = 0; i < str1.length(); i++)
            {
                if (i > 0)
                    if (str1[i - 1] == str1[i])
                        flag = 0;
            }
            if (flag == 1)
                cout << "1\n";
            else
                cout << "0\n";
        }
    }
    return 0;
}
// } Driver Code Ends