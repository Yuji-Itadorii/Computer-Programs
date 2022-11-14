#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node*next ;
    Node * prev;
    Node(int x){
        data = x;
        next = NULL;
        prev= NULL;
    }
};

void printDLL(Node* head){
    Node * temp = head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node * inserBeginDLL(Node* head , int x){
    Node * temp = new Node(x);
    if(head==NULL){
        return temp;
    }

    temp->next = head;
    head->prev = temp;
    head = temp;
    return head;
}

int main(){

    Node * head = new Node(10);
    Node * second = new Node(20);
    Node * third = new Node(30);

    head->next = second;
    second->next = third;

    second->prev = head;
    third->prev = second;

    head = inserBeginDLL(head , 0);
    
    printDLL(head);

    return 0;
}