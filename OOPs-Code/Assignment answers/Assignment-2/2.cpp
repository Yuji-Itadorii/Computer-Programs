#include<iostream>
using namespace std;
class Int{
    public:
    int a;
    void initialization(){
        a=0;
    }
    void set(int x){
        a=x;
    }
    void display(){
        cout<<a;
    }
};

int add(Int A , Int B){
        return A.a+B.a;
    }
int main(){
    Int a,b,c;
    a.initialization();
    b.set(2);
    c.set(3);
    a.set(add(b,c));
    a.display();
    
    return 0;
}