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

void printList(Node * head){
    Node * temp = head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    
}

Node * insertEnd(int x , Node * head){
    Node * temp = new Node(x);
    if(head==NULL){
        return temp;
    }

    Node * curr = head;
    while (curr->next!=NULL) //Note here
    {
        curr = curr->next;
    }
    curr->next=temp;
    return head;
}



int main(){

    Node * head = new Node(10);
    Node * second = new Node(20);
    Node * third = new Node(30);

    head->next = second;
    second->next = third;
    
    head = insertEnd(40 , head);


    printList(head);
    
    return 0;
}