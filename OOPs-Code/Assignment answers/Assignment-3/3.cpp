#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){
    float a ;
    cin>>a;
    int no_digit = floor(log10(floor(a))+1);
    cout<<"The ceiling value of "<<a<<" is "<<ceil(a)<<endl;
    cout<<"The floor value of "<<a<<" is "<<floor(a)<<endl;
    cout<<"The round of value of "<<a<<" is "<<setprecision(no_digit)<<a<<endl;

    return 0;
}