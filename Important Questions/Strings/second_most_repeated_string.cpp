//{ Driver Code Starts
// https://practice.geeksforgeeks.org/problems/second-most-repeated-string-in-a-sequence0534/1

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
       int mx=0;
       string s="";

       unordered_map<string,int>mp;
       for(int i=0;i<n;i++){
           mp[arr[i]]++;
           if(mp[arr[i]]>mx){
               mx=mp[arr[i]];
               s=arr[i];
           }
       }



       mp.erase(s);
       string ans="";
       mx=0;

       for(auto it:mp){
           if(it.second>mx){
               mx=it.second;
               ans=it.first;
           }
       }
       return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}


// } Driver Code Ends