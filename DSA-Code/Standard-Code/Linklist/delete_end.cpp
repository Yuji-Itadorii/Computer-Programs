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

Node * deleteEnd( Node * head){
    if(head==NULL){
        return NULL;
    }
    if (head->next==NULL)
    {
        delete head;
        return NULL;    
    }
    Node* curr = head;
    while (curr->next->next!=NULL)
    {
        curr = curr->next;
    }

    delete curr->next;
        curr->next=NULL;
        return head;
}



int main(){

    Node * head = new Node(10);
    Node * second = new Node(20);
    Node * third = new Node(30);

    head->next = second;
    second->next = third;
    
    head = deleteEnd(head);


    printList(head);
    
    return 0;
}