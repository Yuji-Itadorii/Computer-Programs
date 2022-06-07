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

Node * deleteEnd( Node * head){

    if(head==NULL){
        return NULL;
    }

    if (head->next==head)
    {
        delete head ;
        return NULL;
    }
    
    Node * temp = head;
    while (temp->next->next!=head)
    {
        temp=temp->next;
    }
    
    Node* curr = temp->next;
    temp->next = head;

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

    head = deleteEnd(head);  //******************** TAIL POINTER IS PASSED***********************************

    printList(head);
    
    return 0;
}