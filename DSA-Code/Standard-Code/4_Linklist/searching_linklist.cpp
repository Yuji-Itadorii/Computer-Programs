#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

int searchList(Node * head , int x){
    Node * temp = head;
    int count = 1;
    while (temp!=NULL)
    {
        if(temp->data==x){
            return count;
        }
        else{
            count++;
            temp = temp->next;
        }
    }
    return -1;
}

int main(){

    Node * head = new Node(10);
    Node * second = new Node(20);
    Node * third = new Node(30);

    head->next = second;
    second->next = third;
    
    cout<<searchList(head , 20)<<endl;
    
    return 0;
}