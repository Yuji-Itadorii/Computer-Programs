#include<iostream>
using namespace std;
int Consicutive_1s(int arr[] , int n){
    int res = 0 , curr = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]==0)
        {
            curr = 0;
        }
        else{
            curr++;
            res = max(res , curr);
        }
        
    }
    return res;
}
int main(){
    int arr[] = {1,1,0,0,1,1,1}; 
    cout<<Consicutive_1s(arr , 7 )<<endl;
    return 0;
}