// https://www.spoj.com/problems/EKO/

#include<bits/stdc++.h>
using namespace std;

bool check(int arr[] , int n , int k ,int ans){
    int sum = 0;
    for(int i =0 ; i< n ; i++){
        if(arr[i]>ans){
            sum = sum + (arr[i]-ans);
        }
    }
    // cout<<"sum = "<<sum<<endl;
    return sum>=k;
}

int main(){
    int n , k;
    cin>>n>>k;

    int arr[n];
    int maxa = INT_MIN;
    for(int i =0 ; i< n ; i++){
        cin>>arr[i];
        if(arr[i]>maxa){
            maxa = arr[i];
        }
    }

    


    int low = 0;
    int high = maxa;
    // cout<<low<<high<<endl;
    int res = -1;
    while (low<=high)
    {
        int mid = (low+high)/2;
        // cout<<mid<<endl;
        if(check(arr, n , k , mid)){
            res = max(res, mid);
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }

    cout<<res<<endl;
    return 0;
}