#include<iostream>
using namespace std;

struct Node
{
    int data;
     Node * next;
     Node(){}
     Node(int x){
         data=x;
         next = NULL;
     }
};

void printList(Node * head){
    Node* temp = head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node * insetPos(Node*head , int x , int pos){
    Node * temp = new Node(x);

    if (pos==1)
    {
        temp->next = head;
        return temp;
    }
    
    Node * curr = head;
    for (int i = 1; i <=pos-2 && curr!=NULL; i++)
    {
        curr = curr->next;
    }

    if (curr==NULL)
    {
        return head;
    }
    
    temp->next = curr->next;
    curr->next=temp;
    
    return head;

}


int main(){

    Node *head = new Node(10);
    // head = NULL;
    Node *second = new Node(20);
    Node *third = new Node(30);

    head->next = second;
    second->next = third;

    head = insetPos(head , 15 , 4);

    printList(head);
    
    return 0;
}