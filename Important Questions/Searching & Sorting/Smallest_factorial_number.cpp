// https://practice.geeksforgeeks.org/problems/smallest-factorial-number5929/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
        bool check(int num , int n){
            int count = 0;
            for(int i =5 ; num/i>=1 ; i=i*5){
                count += floor(num/i);
            }
            
            return count >= n;
        }
    
        int findNum(int n)
        {
            int low = 1;
            int high = 5*n;
            int res = -1;
            while(low<=high){
                int mid = (low+high)/2;
                if(check(mid, n)){
                    res =  mid;
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            
            return res;
        }
};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}
// } Driver Code Ends