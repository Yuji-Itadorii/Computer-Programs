#include<iostream>
#include<stack>
using namespace std;

void previousGreaterElement(int arr[] , int n){
    stack<int> s;
    s.push(arr[0]);
    cout<<"-1 ";
    for (int i = 1; i < n; i++)
    {
        while (s.empty()==false && s.top()<=arr[i])
        {
            s.pop();
        }
        int pge = (s.empty())? -1 : s.top();
        cout<<pge<<" ";
        s.push(arr[i]);
    }
    
}

int main(){
    int arr[] = {13 , 15 , 12 , 50, 45};
    previousGreaterElement(arr ,5 );
    return 0;
}