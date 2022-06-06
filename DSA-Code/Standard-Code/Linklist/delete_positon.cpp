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

Node * deletePos( Node * head , int pos){
    
    if(head==NULL)
     return NULL;
    Node* temp = head;
    if (pos==1)
    {
        temp= head->next;
        delete head;
        return temp;
    }
    
    for (int i = 1; i <pos-1; i++)
    {
        temp = temp->next;
    }
    
     Node * curr = temp->next;

     temp->next = temp->next->next;
     delete curr;

     return head; 
    
}



int main(){

    Node * head = new Node(10);
    Node * second = new Node(20);
    Node * third = new Node(30);

    head->next = second;
    second->next = third;
    
    head = deletePos(head , 3);


    printList(head);
    
    return 0;
}