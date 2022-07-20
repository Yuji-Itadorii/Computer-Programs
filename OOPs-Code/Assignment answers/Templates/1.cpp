#include<iostream>
using namespace std;

template <class T>
class array{
    T *arr;
    int size;
    public:
    array(){}
    array(int s){
        size = s;
        arr = new T[size];
    }

    void setValue(){
        cout<<"Enter the values of array";
        for (int i = 0; i < size; i++)
        {
            cin>>arr[i];
        }
    }

    T sumarr(){
        T sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum = sum + arr[i];
        }
        return sum;
    }
};


int main (){

    array<float> A1(5);

    A1.setValue();
    cout<<A1.sumarr()<<endl;


    return 0 ;

}