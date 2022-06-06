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

Node * deleteEndDLL(Node* head , int pos){
    
    if (pos==1)
    {
        Node * temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp ;
        return head;
    }

    if (head->next==NULL)
    {
        delete head ;
        return NULL;
    }
    

    if (head==NULL)
    {
        return NULL;
    }

    Node * curr = head ;
    for (int i = 1; i <pos-1; i++)
    {
        curr = curr->next;
    }
    Node * temp = curr->next;

    if (temp->next!=NULL)
    {
        temp->next->prev = curr;
    }
    
    curr->next = temp->next;

    delete temp;

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

    head = deleteEndDLL(head  , 3);
    
    printDLL(head);

    return 0;
}