// https://practice.geeksforgeeks.org/problems/longest-valid-parentheses5657/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxLength(string str){
        // code here
    int n = str.length();
 
    // Create a stack and push -1 as
    // initial index to it.
    stack<int> stk;
    stk.push(-1);
 
    // Initialize result
    int result = 0;
 
    for (int i = 0; i < n; i++)
    {

        if (str[i] == '(')
            stk.push(i);
    
        else
        {

            stk.pop();
            
             
            if (!stk.empty())
                result = max(result, i - stk.top());
            else
                stk.push(i);
        }
    }
 
    return result;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends