// https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1

//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node *inputList(int size)
{
    Node *head, *tail;
    int val;

    cin >> val;
    head = tail = new Node(val);

    while (--size)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
}

Node *findIntersection(Node *head1, Node *head2);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        Node *head1 = inputList(n);
        Node *head2 = inputList(m);

        Node *result = findIntersection(head1, head2);

        printList(result);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node *findIntersection(Node *curr1, Node *curr2)
{

    Node *head1 = curr1;
    Node *head2 = curr2;
    Node *ans = new Node(0);
    Node *res = ans;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data == head2->data)
        {
            // cout<<head1->data<<" ";
            Node *temp = new Node(0);
            temp->data = head1->data;
            res->next = temp;
            res = res->next;
            head1 = head1->next;
            head2 = head2->next;
        }
        else if (head1->data < head2->data)
        {
            head1 = head1->next;
        }
        else
        {
            head2 = head2->next;
        }
    }

    return ans->next;
}