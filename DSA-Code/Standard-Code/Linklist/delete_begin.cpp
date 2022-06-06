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

Node * deleteBegin( Node * head){
    if(head==NULL){
        return NULL;
    }
    else
    {
      Node *temp = head->next;
      delete head;
      return temp;  
    }
    
}



int main(){

    Node * head = new Node(10);
    Node * second = new Node(20);
    Node * third = new Node(30);

    head->next = second;
    second->next = third;
    
    head = deleteBegin(head);


    printList(head);
    
    return 0;
}