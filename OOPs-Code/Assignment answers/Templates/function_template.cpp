#include<iostream>
using namespace std;

template <class t1 , class t2>

float averagee(t1 a , t2 b){
    return (a+b)/2;
}

template <class t>
void swapp(t &a , t &c){
    t temp = a;
    a = c;
    c = temp;
}



int main(){

    cout<<averagee<float , float>(2,3)<<endl;

    char a = 'A';
    char b = 'B';

    swapp<char>(a,b);
    cout<<a<<" "<<b;
    
    return 0;
}