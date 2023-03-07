// https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int binarySearch(int arr[] , int n , int x , char t){
    int i = 0 , j = n-1;
    int res=-1;
    while(i<=j){
        int mid=i+(j-i)/2;
        if(arr[mid]==x){
            res=mid;
            if(t=='f'){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        else if(arr[mid]<x){
            i=mid+1;
        }
        else{
            j=mid-1;
        }
    }
    return res;
}

vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int> res;
    int a = binarySearch(arr , n , x , 'f');
    res.push_back(a);
    int b = binarySearch(arr , n , x, 'l');
    res.push_back(b);
    return res;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends