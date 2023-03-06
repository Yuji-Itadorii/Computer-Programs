// https://practice.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1

//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool solve(string str1, string str2)
    {
        
        // Your code here
        unordered_map<char , char> m;
        for(int i = 0 ; i< str1.size() ; i++){
            if(m.find(str1[i]) == m.end()){
                m[str1[i]] = str2[i];
            }
            else if(m[str1[i]] != str2[i] ){
                return false;
            }
        }
        return true;
    }
    
    bool areIsomorphic(string s1, string s2)
    {
        if(s1.size() != s2.size()){
            return false;
        }
        
        return solve(s1, s2 ) && solve(s2, s1);
        
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends