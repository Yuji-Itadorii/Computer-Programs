// https://practice.geeksforgeeks.org/problems/minimum-swaps-for-bracket-balancing2704/1

//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:

    int minimumNumberOfSwaps(string s){
        int n = s.size();
        vector<int> pos;
        
        for(int i =0 ; i< n ; i++){
            if(s[i] == '['){
                pos.push_back(i);
            }
        }
        
        int count = 0;
        int p =0;
        int sum =0;
        
        for(int i =0 ; i< n ; i++){
            if(s[i] == '['){
                count++;
                p++;
            }
            else{
                count--;
            }
            
            if(count<0){
                sum += pos[p] - i;
                swap(s[i] , s[pos[p]]);
                p++;
                count = 1;
            }
        }
        
        return sum;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
} 
// } Driver Code Ends