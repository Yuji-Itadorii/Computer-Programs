#include<iostream>
using namespace std;

void fun(int a){
    cout<<"This is func  "<<a<<endl;
}

template <class t>
void fun(t a){
    cout<<"This is templatised func  "<<a<<endl;
}

int main(){

    fun(1); //Exact match has higher priority so Templatised function will not me executed

    fun('A');
    fun(5.001);

    
    return 0;
}