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

Node * deleteEnd( Node * tail){

    if(tail==NULL){
        return NULL;
    }

    if (tail->next==tail)
    {
        delete tail ;
        return NULL;
    }

    int t = tail->next->data;
    tail->next->data = tail->data;
    tail->data = t;
    Node * curr  = tail->next;
    tail->next = tail->next->next;

    delete curr;
    

    return tail;

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

    head = deleteEnd(fourth);  //******************** TAIL POINTER IS PASSED***********************************

    printList(head);
    
    return 0;
}