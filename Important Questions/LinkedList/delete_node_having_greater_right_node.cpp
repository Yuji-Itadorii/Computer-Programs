// https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void print(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
public:
    Node *reverseList(struct Node *head)
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

    Node *compute(Node *head)
    {
        // your code goes here
        Node *curr = reverseList(head);
        Node *res = curr;
        Node *ans = res;
        curr = curr->next;
        while (curr != NULL)
        {
            if (curr->data >= res->data)
            {
                res->next = curr;
                res = res->next;
            }

            curr = curr->next;
        }
        res->next = NULL;
        return reverseList(ans);
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int K;
        cin >> K;
        struct Node *head = NULL;
        struct Node *temp = head;

        for (int i = 0; i < K; i++)
        {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else
            {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout << endl;
    }
}

// } Driver Code Ends