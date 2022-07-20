#include<iostream>
using namespace std;

template <class t1=int , class t2 = double>

class myclass
{

public:

    t1 data1;
    t2 data2;
    myclass(){

    }
    void display(){
        cout<< this->data1 <<" "<<this->data2<<endl;
    }
};


int main(){

    myclass <> obj;
    myclass <int , int> obj2;

    obj.data1 = 10;
    obj.data2 = 234.45;
    obj.display();
    obj2.data1 = 10;
    obj2.data2 = 234.45;
    obj2.display();
    
    return 0;
}