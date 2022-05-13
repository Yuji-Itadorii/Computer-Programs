#include<iostream>
// #include<bit
#include<cmath>
using namespace std;
bool isArmstrong(int n){
    int copy = n;
    int p = floor(log10(n))+1;
    cout<<"the no of digits "<<p<<endl;
    int sum = 0;
    while (n>0)
    {
        int digit = 0;
        digit = n%10;
        sum = sum + pow(digit , p);
        n=n/10;
    }
    cout<<"the sum is :  "<<sum<<endl;
    if(copy==(sum))
    return true;
    else
    return false;
}
int main(){
    int n;
    cin>>n;
    if(isArmstrong(n)){
        cout<<"Yes!";
    }
    else{
        cout<<"No!";
    }
    return 0;
}