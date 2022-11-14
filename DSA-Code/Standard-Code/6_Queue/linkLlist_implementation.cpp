#include<iostream>
using namespace std;
struct node
{
    int data;
    node * next;
    node(int x){
        data = x;
        next = NULL;
    }
};
struct queue
{
    node * front , *rear;
    int size;
    queue(){
        front = NULL;
        rear = NULL;
        size = 0;
    }

    void enqueue(int x){
        node * temp = new node(x);
        if(front==NULL){
            front = rear = temp;
        }
        rear->next = temp;
        rear = temp;
        size++;
    }

    void dequeue(){
        if(front == NULL){
            return;
        }
        node * temp = front;
        front = front->next;
        if(front == NULL){
            rear=NULL;
        }
        delete(temp);
        size--;
    }

    int getFront(){
        return front->data;
    }

    int getRear(){
        return rear->data;
    }

    int getSize(){
        return size;
    }
};


int main(){
    queue q; 
	q.enqueue(10); 
	q.enqueue(20); 
	q.dequeue(); 
	q.dequeue(); 
	q.enqueue(30); 
	q.enqueue(40); 
	q.enqueue(50); 
	q.dequeue(); 
	cout << "queue Front : " << (q.front)->data << endl; 
	cout << "queue Rear : " << (q.rear)->data; 
    
    return 0;
}