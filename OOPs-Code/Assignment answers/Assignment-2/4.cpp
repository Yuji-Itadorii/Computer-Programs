#include<iostream>
using namespace std;
bool isPalindrom(int n){
    int copy = n;
    int rev = 0;
    while (n>0)
    {
        rev = rev*10 + n%10;
        n=n/10;
    }
    if(copy==rev)
    return true;
    else
    return false;
}
int main(){
    int n;
    cin>>n;
    if(isPalindrom(n)){
        cout<<"Yes!";
    }
    else{
        cout<<"No!";
    }
    return 0;
}