#include<iostream>
using namespace std;

struct  Node
{
    int data ;
    Node * next;
    Node * prev;
    Node(int d){
        data = d;
        next = NULL;
        prev = NULL;
    }
};

void printList(Node * head){
    if(head==NULL){
        return;
    }
    Node * tmep = head;
    do
    {
        cout<<tmep->data<<" ";
        tmep = tmep->next;
    } while (tmep!=head);
}


int main(){

    Node * head = new Node(10);
    Node * second = new Node(20);
    Node * third = new Node(30);

    head->next = second;
    head->prev = third;

    second->next = third;
    second->prev = head;

    third->next = head;
    third->prev = second;

    printList(head);
    
    return 0;
}