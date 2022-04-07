#include<iostream>
using namespace std;
class myArray{
    public:
    int total_size , used_size;
    int *ptr;
    myArray(int tSize , int usize){
        total_size = tSize;
        used_size = usize;
        ptr = new int[tSize];
    };

    void set(){
        for (int i = 0; i < used_size; i++)
        {
            cin>>ptr[i];
        }    
    }
    void get(){
        for (int i = 0; i < used_size; i++)
        {
            cout<<ptr[i]<<" ";
        }    
    }
};

int main(){

    myArray marks(10 , 2);
    cout<<"Enter the elements : "<<endl;
    marks.set();
    cout<<"The elements are : "<<endl;
    marks.get();
    
    return 0;
}