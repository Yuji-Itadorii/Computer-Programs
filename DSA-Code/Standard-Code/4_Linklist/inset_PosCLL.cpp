#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node * next ;
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList (Node * head){

    if(head==NULL)
        return;

    Node * temp = head ;
    do
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    } while (temp!=head);
}


Node * insertBegin(Node * head , int d){
    Node * temp = new Node(d);
    
    temp->next = head->next;
    head->next = temp;

    int t = head->data;
    head->data = temp->data;
    temp->data = t;

    return head;

}

Node * insertPos(Node * head , int d , int pos){

    Node * temp = new Node(d);
    if(head==NULL){
        temp->next = temp;
        return temp;
    }

    if (pos==1)
    {
        return insertBegin(head , d);
    }

    Node * curr = head ;
    for (int i = 1; i < pos-1; i++)
    {
        curr = curr->next;
    }

    temp->next = curr->next;
    curr->next = temp;
    return head;

}

int main(){

    Node * head = new Node(10);
    Node * second = new Node(20);
    Node * third = new Node(30);
    Node * fourth = new Node(40);

    head->next = second ;
    second->next = third ;
    third->next = fourth;
    fourth->next = head;

    head = insertPos(head, 25 , 5);

    printList(head);
    
    return 0;
}