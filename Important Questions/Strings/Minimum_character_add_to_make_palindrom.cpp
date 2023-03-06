// https://www.geeksforgeeks.org/minimum-characters-added-front-make-string-palindrome/

//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    
    vector<int> getLPS(string str){
        int n = str.size();
        vector<int> lps(n);
        
       int len = 0;
       lps[0] = 0;
       int i = 1;
       while(i<n){
           if(str[i] == str[len]){
               len++;
               lps[i] = len;
               i++;
           }
           else{
               if(len == 0){
                   lps[i] = 0;
                   i++;
               }
               else{
                   len = lps[len-1];
               }
           }
       }
        
       return lps;
    }
   

    int minChar(string str){
        string reverse_string = str;
        reverse(reverse_string.begin() , reverse_string.end());
        
        string concatenated_string = str + '$' + reverse_string;
        
        vector<int> lps = getLPS(concatenated_string);
        
        return (str.size() - lps.back());
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends