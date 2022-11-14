#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

void nextGreaterElement(int arr[] , int n){
    stack<int> s;
    vector<int> v;
    s.push(arr[n-1]);
    v.push_back(-1);
    for (int i = n-2; i>=0; i--)
    {
        while (s.empty()==false && s.top()<=arr[i])
        {
            s.pop();
        }
        int nge = (s.empty())? -1 : s.top();
        v.push_back(nge);
        s.push(arr[i]);
    }
    reverse(v.begin() , v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
}

int main(){
    int arr[] = {13 , 15 , 12 , 50, 60};
    nextGreaterElement(arr ,5 );
    return 0;
}