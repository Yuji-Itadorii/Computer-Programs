#include<iostream>
#include<climits>
using namespace std;

struct queue_array
{
    int *arr;
    int cap;
    int size;
    int front;
    int rear;
    queue_array(int n){
        cap = n;
        size = 0;
        front = 0;
        rear = cap -1;
        arr = new int[cap];
    }

    bool isFull(){
        return (size == cap);
    }

    bool isEmpty(){
        return (size==0);
    }

    int getFront(){
        if(isEmpty()){
            return INT_MIN;
        }
        else{
            return arr[front];
        }
    }

    int getrear(){
        if(isEmpty()){
            return INT_MIN;
        }
        else{
            return arr[rear];
        }
    }

    void enque(int x){
        if(isFull()){
            cout<<"Full"<<endl;
            return;
        }
        rear = (rear+1)%cap;
        arr[rear]  = x;
        size++;
    }

    void deque(){
        if(isEmpty()){
            cout<<"Empty!!"<<endl;
            return ;
        }
        front = (front+1)%cap;
        size--;
    }
};


int main(){

    queue_array q(6);
    q.enque(10);
    q.enque(20);
    q.enque(30);
    q.enque(40);
    q.enque(50);
    q.enque(60);

    cout<<q.front<<endl;
    cout<<q.getFront()<<endl;
    cout<<q.getrear()<<endl;

   q.deque();
   q.deque();

    cout<<q.front<<endl;
    cout<<q.getFront()<<endl;
    cout<<q.getrear()<<endl;

    
    return 0;
}