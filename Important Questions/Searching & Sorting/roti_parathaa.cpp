#include<bits/stdc++.h>
using namespace std;

bool check(int arr[] , int n ,int paratha,  int mid){
    int time =0;
    int count =0;
    for(int i =0 ; i<n ; i++){
        time = arr[i];
        int j = 2;
        while (time<=mid)
        {
            count++;
            time = time+ (arr[i]*j);
            j++;
        }
        if(count>=paratha) return true;
    }
    return false;
}

int main(){
    int paratha;
    cin>>paratha;
    int n;
    cin>>n;
    int arr[n];
    for(int i =0 ; i<n ; i++){
    cin>>arr[i];
    }
    int low = 0;
    int high = 1e8;
    int res = 0;
    while (low<=high)
    {
        int mid = (low+high)/2;
        if(check(arr , n , paratha, mid)){
            res= mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    cout<<res;
    
    return 0;
}