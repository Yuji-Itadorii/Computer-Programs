#include<iostream>
using namespace std;
void leader_element_Array(int arr[] , int n){
    int curr_leader = arr[n-1];
    cout<<curr_leader<<" ";
    for (int i = n-2; i >= 0; i--)
    {
        if (arr[i]>=curr_leader)
        {
            curr_leader=arr[i];
            cout<<curr_leader<<" ";
        }
        
    }
    
}
int main(){
    int arr[] = {1,2,9,6,7}; 
    leader_element_Array(arr , 5 );
    return 0;
}