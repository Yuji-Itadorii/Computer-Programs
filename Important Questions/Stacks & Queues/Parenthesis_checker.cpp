// https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to check if brackets are balanced or not.
    bool matching(char a, char b)
    {
        return (a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']');
    }

    bool ispar(string x)
    {
        stack<char> s;
        for (char str : x)
        {
            if (str == '(' || str == '{' || str == '[')
            {
                s.push(str);
            }
            else
            {
                if (s.empty() != false)
                {
                    return false;
                }
                if (matching(s.top(), str) == false)
                {
                    return false;
                }
                else
                {
                    s.pop();
                }
            }
        }

        return (s.empty() == true);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    string a;
    cin >> t;
    while (t--)
    {
        cin >> a;
        Solution obj;
        if (obj.ispar(a))
            cout << "balanced" << endl;
        else
            cout << "not balanced" << endl;
    }
}
// } Driver Code Ends