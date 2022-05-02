// create class Size(static int a, double b, char c, const int d), find the size of object?
#include<iostream>
using namespace std;
class size_of_class{
    public:
    double b;
    const int d=0;
    static int  a;
    char c;

};
int main(){
    size_of_class x;
    cout<<sizeof(x.a)<<endl;
    cout<<sizeof(x.b)<<endl;
    cout<<sizeof(x.c)<<endl;
    cout<<sizeof(x.d)<<endl;
    cout<<sizeof(x)<<endl;

    return 0;
}