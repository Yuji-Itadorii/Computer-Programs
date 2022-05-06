#include<iostream>
using namespace std;

int main(){
    int n ,sum = 0;
    cin>>n;
    while (n>0)
    {
        int digit = n%10;
        sum = sum +digit;
        n=n/10;
    }

    cout<<"The sum of digits of number "<<n<<" is : "<<sum;
    
    return 0;
}