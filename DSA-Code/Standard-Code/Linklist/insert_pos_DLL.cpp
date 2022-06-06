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

Node * inserPosDLL(Node* head , int x , int pos){
    Node * temp = new Node(x);
    if (head==NULL)
    {
        return temp;
    }
    
    if (pos==1)
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
        return head;
    }

    Node * curr  = head;
    for (int i = 1; i < pos-1 && curr->next!=NULL; i++)
    {
        curr = curr->next;
    }

    temp->next = curr->next;
    if(curr->next!=NULL){
        curr->next->prev = temp;
    }
    curr->next = temp;
    temp->prev = curr;

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

    head = inserPosDLL(head , 0 , 4);
    
    printDLL(head);

    return 0;
}