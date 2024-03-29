// https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1

//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to evaluate a postfix expression.
    int eval(int a, int b, char oper)
    {
        if (oper == '+')
            return a + b;
        else if (oper == '-')
            return a - b;
        else if (oper == '*')
            return a * b;
        return a / b;
    }

    int evaluatePostfix(string s)
    {
        // Your code here
        int ans = 0;
        stack<int> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
                st.push(s[i] - '0');
            else
            {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                ans = eval(num1, num2, s[i]);
                st.push(ans);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--)
    {
        string S;
        cin >> S;
        Solution obj;

        cout << obj.evaluatePostfix(S) << endl;
    }
    return 0;
}

// } Driver Code Ends