// https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data;
        node = node->next;
    }
    cout << "\n";
}

// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
public:
    Node *reverseList(Node *head)
    {

        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        Node *curr = head;
        Node *prev = NULL;

        while (curr != NULL)
        {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    Node *addOne(Node *head)
    {
        head = reverseList(head);
        Node *temp = head;

        while (temp != NULL)
        {
            if (temp->next == NULL && temp->data == 9)
            {
                temp->data = 1;
                Node *newnode = new Node(0);
                newnode->next = head;
                head = newnode;
                temp = temp->next;
            }
            else if (temp->data == 9)
            {
                temp->data = 0;
                temp = temp->next;
            }
            else
            {
                temp->data = temp->data + 1;
                break;
            }
        }

        head = reverseList(head);
        return head;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Node *head = new Node(s[0] - '0');
        Node *tail = head;
        for (int i = 1; i < s.size(); i++)
        {
            tail->next = new Node(s[i] - '0');
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends