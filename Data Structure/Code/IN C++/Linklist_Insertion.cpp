#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * next;
};

void linkedListTranversal(Node * ptr){
    while (ptr!=NULL)
    {
        cout<<"Element : "<<ptr->data<<endl;
        ptr = ptr->next;
    }
    
}

Node * insertAtbeg( Node * head , int Data){
    Node * ptr = new Node();
    ptr->data = Data;
    ptr->next = head ;

    return ptr;
}

Node * insertAtINdex( Node * head , int Data , int index){
    Node * ptr = new Node();
    ptr->data = Data;
     Node * p = head;
    int i =0 ;
     while (i!=index-1)
     {
       p = p->next;
       i++;
     }
     
    ptr->next = p->next ;
    p->next = ptr;

    return head;
}
Node * insertAtend( Node * head , int Data){
    Node * ptr = new Node();
    ptr->data = Data;
     Node * p = head;
     while (p->next!=NULL)
     {
       p = p->next;
     }
     
    p->next = ptr;
    ptr->next = NULL ;

    return head;
}

Node * insertNode( Node * head , Node * prevNode ,  int Data){
    Node * ptr = new Node();
    ptr->data = Data;
     
     ptr->next = prevNode->next;
     prevNode->next = ptr;
    

    return head;
}

int main(){
    
    Node * head ;
    Node * second;
    Node * third;


    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1;
    head->next = second;

    second->data=2;
    second->next=third;
    
    third->data=3;
    third->next=NULL;
    int a;
    linkedListTranversal(head);
    cout<<"Enter your new data to be inserted at the first : "<<endl;
    cin>>a;
    // head = insertAtbeg(head , a);
    // insertAtINdex(head , 34 , 2);
    // head = insertAtend(head, a);
    head = insertNode(head , second , a);
    linkedListTranversal(head);

    return 0;
}