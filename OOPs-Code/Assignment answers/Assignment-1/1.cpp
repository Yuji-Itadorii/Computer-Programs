#include<iostream>
// #include<algorithm>
#include<math.h>
using namespace std;
class Point1 {
    int a , b;
    public:
    void set_ab(int A , int B){
        a=A;
        b=B;
    }
    friend int distance(Point1 x , Point1 y);
};

int distance(Point1 x  , Point1 y){
    int distance = sqrt(pow((x.a - y.a),2)+pow((x.b - y.b),2));
    return distance;
}
int main(){
    Point1 x , y ;
    x.set_ab(2,7);
    y.set_ab(2,2);
    cout<<distance(x , y);

    return 0;
}