#include<iostream>
using namespace std;

int factorial(int n){
    if(n==0)
    return 1;
    return n*factorial(n-1);
}

int nCr(int n ,int r){
    int res = factorial(n)/(factorial(r)*factorial(n-r));
}

int main(){
    for (int i = 0; i <5; i++)
    {
        for (int j= 0; j <5-i; j++)
        {
            cout<<" ";
        }

        for (int j= 0; j <=i; j++)
        {
            cout<<nCr(i,j)<<" ";
        }

        cout<<endl;
        
    }
    
    return 0;
}