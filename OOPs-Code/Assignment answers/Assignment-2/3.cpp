#include<iostream>
using namespace std;
void PrintReverse(int n){
    int rev = 0;
    while (n>0)
    {
        rev = rev*10 + n%10;
        n=n/10;
    }
    cout<<rev<<endl;
}
int main(){
    int n;
    cin>>n;
    PrintReverse(n);
    return 0;
}