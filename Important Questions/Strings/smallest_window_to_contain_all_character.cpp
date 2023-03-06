// https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the smallest window in the string s consisting
    // of all the characters of string p.
    string smallestWindow(string s, string p)
    {
        int n = s.size();
        int m = p.size();

        if (m > n)
        {
            return "-1";
        }

        int count_s[256] = {0};
        int count_p[256] = {0};

        for (int i = 0; i < m; i++)
            count_p[p[i]]++;

        int start = 0, start_index = -1, min_len = INT_MAX;
        int count = 0;

        for (int j = 0; j < n; j++)
        {
            count_s[s[j]]++;

            if (count_s[s[j]] <= count_p[s[j]])
                count++;

            if (count == m)
            {

                while (count_s[s[start]] > count_p[s[start]] || count_p[s[start]] == 0)
                {

                    if (count_s[s[start]] > count_p[s[start]])
                        count_s[s[start]]--;
                    start++;
                }

                int len_window = j - start + 1;
                if (min_len > len_window)
                {
                    min_len = len_window;
                    start_index = start;
                }
            }
        }

        if (start_index == -1)
        {
            return "-1";
        }

        return s.substr(start_index, min_len);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string pat;
        cin >> pat;
        Solution obj;
        cout << obj.smallestWindow(s, pat) << endl;
    }
    return 0;
}
// } Driver Code Ends