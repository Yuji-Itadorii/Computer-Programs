#include<iostream>
using namespace std;
int maximumSumSubarray(int arr[] , int n){
    int sum = arr[0];
    int maxEnding = arr[0];
    for (int i = 0; i < n; i++)
    {
        maxEnding = max(maxEnding+arr[i],arr[i]);
        sum = max(sum , maxEnding);
    }
    return sum;
}

int overMaxSum(int arr[] , int n){
    int max_normal = maximumSumSubarray(arr , n);
    if(max_normal<0)
    return max_normal;
    int arr_sum = 0;
    for (int i = 0; i < n; i++)
    {
        arr_sum+=arr[i];
        arr[i]=-arr[i];
    }
    int max_circular = arr_sum + maximumSumSubarray(arr , n);
    return max(max_normal , max_circular);
    
}
int main(){
    int arr[] = {8,-4,3,-5,4}; 
    cout<<overMaxSum(arr , 5)<<endl;
    return 0;
}