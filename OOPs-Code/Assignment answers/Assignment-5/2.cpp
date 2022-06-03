#include<iostream>
using namespace std;

class pointer{
    public:
    int * ptr;
    int size;
};

void reverseArray(pointer p){
    int *arr = p.ptr ;
    int size = p.size;
    int l = 0 , r=size-1;
    while (l<=r)
    {
        swap(arr[l],arr[r]);
        l++;
        r--;
    }
}

int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    pointer p ;
    p.ptr = arr;
    p.size = 10;
    reverseArray(p);
    for(int i = 0; i<10 ; i++)
        cout<<arr[i]<<" ";
    return 0;
}