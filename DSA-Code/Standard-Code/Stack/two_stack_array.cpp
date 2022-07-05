#include<iostream>
using namespace std;
struct two_stack_array
{
    int top1;
    int top2;
    int cap;
    int *arr;
    two_stack_array(int n){
        cap = n;
        top1 = -1;
        top2 = cap;
        arr = new int[n];
    }

    void push1(int x){
        if(top1<top2-1){
            top1++;
            arr[top1] = x;
        }
        else{
            cout<<"Stack Full"<<endl;
        }
    }
    void push2(int x){
        if(top1<top2-1){
            top2--;
            arr[top2] = x;
        }
        else{
            cout<<"Stack Full"<<endl;
        }
    }

    int pop1(){
        if(top1>=0){
            int x = arr[top1];
            top1--;
            return x;
        }
        else{
            exit(1);
        }
    }
    int pop2(){
        if(top2<cap){
            int x = arr[top2];
            top2++;
            return x;
        }
        else{
            exit(1);
        }
    }
};


int main(){

    two_stack_array s(5) ;
    s.push1(10);
    s.push1(20);
    s.push2(30);
    s.push2(40);
    s.push2(50);
    // s.push2(60);
    cout<<s.pop1()<<endl;
    cout<<s.pop2();
    
    return 0;
}