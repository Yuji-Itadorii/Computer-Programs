#include<iostream>
using namespace std;

int main(){
    int a , b , c;
    cin>>a>>b>>c;
    int d = max(a,b);
    int result = max(d,c);

    cout<<"The maximum number is : "<<result<<endl;
    
    return 0;
}