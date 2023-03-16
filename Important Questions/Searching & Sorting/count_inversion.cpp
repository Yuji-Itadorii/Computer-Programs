// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
  
 long long int merge(long long int arr[],long long int temp[],long long int left,long long int mid,long long int right){
        long long int i,j,k;
        long long int count =0;
        i=left;
        j=mid;
        k=left;
        while((i<=mid-1)&&(j<=right)){
            if(arr[i]<=arr[j])temp[k++]=arr[i++];
            else {
                temp[k++]=arr[j++];
                count+=mid-i;
            }
        }
        while(i<=mid-1)temp[k++]=arr[i++];
        while(j<=right)temp[k++]=arr[j++];
        
        for(i=left;i<=right;i++)arr[i]=temp[i];
        return count;
    }
    
    long long int merge_sort(long long int arr[],long long int temp[], long long int left,long long int right){
        long long int mid, count=0;
        if(right>left){
            mid=(right+left)/2;
            
            count+=merge_sort(arr,temp,left,mid);
            count+=merge_sort(arr,temp,mid+1,right);
            
            count+=merge(arr,temp,left,mid+1,right);
        }
        return count;
    }
    
    long long int inversionCount(long long int arr[], long long int N)
    {
        long long int temp[N];
        return merge_sort(arr,temp,0,N-1);
    }
};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends