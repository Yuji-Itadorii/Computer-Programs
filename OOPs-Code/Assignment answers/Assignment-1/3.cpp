#include<iostream>
using namespace std;
class cylinder{
    int r, h;
    public:
    cylinder(int a , int b){
        r = a ;
        h = b;
    }
    void volume(){
        cout<<"The volume of cylinder is : "<<2*3.14*r*r*h<<endl;
    }
    void baseArea(){
        cout<<"The base area is : "<<2*3.14*r*r<<endl;
    }
    void surfaceArea( ){
        cout<<"The surface are is : "<<2*3.14*r*(h+r)<<endl;
    }
};
int main(){
    cylinder c(1,1);
    c.volume();
    c.baseArea();
    c.surfaceArea();
    return 0;
}