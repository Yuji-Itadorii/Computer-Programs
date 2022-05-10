#include<iostream>
using namespace std;
int max_diffrence(int arr[] , int n){
    int res = arr[1] - arr[0];
    int minValue = arr[0];
    for (int i = 1; i < n; i++)
    {
        res = max(res , arr[i]-minValue);
        minValue = min(minValue , arr[i]);
    }
    return res;
    
}
int main(){
    int arr[] = {1,2,9,6,7}; 
    cout<<max_diffrence(arr , 5 )<<endl;
    return 0;
}