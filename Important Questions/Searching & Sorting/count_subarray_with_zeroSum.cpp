// https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1

//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) {
        
        unordered_map<long long , long long> m;
        long long count = 0;
        long long prefix_sum = 0;
        m[0] = 1;
        for(int i =0 ; i<n ; i++){
            prefix_sum += arr[i];
            
            if(m.find(prefix_sum)!=m.end()){
                count = count+ m[prefix_sum];
                m[prefix_sum]++;
            }
            else{
                m[prefix_sum]++;   
            }
        }
        
        
        return count;
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<long long int> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}
// } Driver Code Ends