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

Node * reverseK(Node * head , int k){
    Node * curr = head , *prevFirst = NULL;
    bool isFirstpass = true;
    while (curr!=NULL)
    {
        Node * first = curr , *prev = NULL;
        int count = 0;
        while (curr!=NULL && count<k)
        {
            Node * next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if(isFirstpass){
            head = prev;
            isFirstpass = false;
        }
        else{
            prevFirst->next = prev;
        }

        prevFirst = first;
    }

    return head;
}

int main(){

    Node * head = new Node(10);
    Node * second = new Node(20);
    Node * third = new Node(30);
    Node * fourth = new Node(40);
    Node * fivth = new Node(50);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fivth;
    
    printList(head);
    cout<<endl;
    head = reverseK(head , 3);
    printList(head);
    
    return 0;
}