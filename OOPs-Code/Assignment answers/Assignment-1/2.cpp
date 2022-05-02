#include<iostream>
using namespace std;
class point {
    int x ,y ,z;
    public:
    void set (int a, int b , int c ){
        x=a;
        y=b;
        z=c;
    }
    void display(){
        cout<<x<<","<<y<<","<<z<<endl;
    }
    friend point midpoint(point _1 , point _2);
};

point midpoint(point _1 , point _2){
    point mid ;
    mid.x = (_1.x+_2.x)/2;
    mid.y = (_1.y+_2.y)/2;
    mid.z = (_1.z+_2.z)/2;
    return mid;
}
int main(){
    point x1 , x2 , x3;
    x1.set(6,7,8);
    x2.set(8,9,10);
    x3 = midpoint(x1 , x2);
    x3.display();
    return 0;
}