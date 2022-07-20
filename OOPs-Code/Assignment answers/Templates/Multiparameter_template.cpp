#include<iostream>
using namespace std;

template <class t1 , class t2>

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

    myclass<int , float> obj;

    obj.data1 = 10;
    obj.data2 = 234.45;
    obj.display();
    
    return 0;
}