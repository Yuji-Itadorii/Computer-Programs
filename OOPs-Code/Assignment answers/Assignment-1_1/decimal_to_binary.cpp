#include<iostream>
using namespace std;

class decimal{
    int a;
    public:
    decimal(int x){
        a=x;
    }
    int get(){
        return a;
    }
    void put(int x){
        a=x;
    }
    
    long long getBinary(){
        if(a<=0){
            return 0;
        }
    int reminder = a%2;
    a = a/2;
    return reminder + 10*getBinary();
    }
};



int main(){
    
    decimal num(10);
    cout<<num.get()<<endl;
    
    cout<<num.getBinary();
    
    
    return 0;
}