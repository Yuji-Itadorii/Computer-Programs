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
int main(){
    int arr[] = {-3,8,-2,4,-5,6}; 
    cout<<maximumSumSubarray(arr , 6)<<endl;
    return 0;
}