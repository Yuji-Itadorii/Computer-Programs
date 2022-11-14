#include<iostream>
using namespace std;
int maximum_EvenOdd_lenght(int arr[] , int n){
    int res = 1 , curr = 1;
    for (int i = 1; i < n; i++)
    {
        if ((arr[i]%2==0 && arr[i-1]%2!=0)||(arr[i-1]%2==0 && arr[i]%2!=0))
        {
            curr++;
        }
        else{
            curr = 1;
        }
        res = max(res , curr);
    }
    return res;
}
int main(){
    int arr[] = {5,10,20,6,3,8}; 
    cout<<maximum_EvenOdd_lenght(arr , 6)<<endl;
    return 0;
}