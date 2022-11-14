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

int main(){

    Node * head = new Node(10);
    Node * second = new Node(20);
    Node * third = new Node(30);
    Node * fourth = new Node(40);

    head->next = second ;
    second->next = third ;
    third->next = fourth;
    fourth->next = head;

    printList(head);
    
    return 0;
}