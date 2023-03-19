// https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
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

struct Node *buildList(int size)
{
    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
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
    cout << endl;
}

// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
public:
    // Function to add two numbers represented by linked list.
    struct Node *reverse(struct Node *head)
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

    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {
        Node *f = reverse(first);
        // print(f);
        Node *s = reverse(second);
        // print(s);

        Node *res = new Node(0);
        Node *ans = res;
        int carry = 0;
        while (f != NULL && s != NULL)
        {
            int num = f->data + s->data + carry;
            Node *temp = new Node(0);
            if (num > 9)
            {
                num = num % 10;
                temp->data = num;
                carry = 1;
            }
            else
            {
                temp->data = num;
                carry = 0;
            }

            ans->next = temp;
            ans = ans->next;
            f = f->next;
            s = s->next;
        }

        if (f == NULL)
        {
            while (s != NULL)
            {
                int num = s->data + carry;
                Node *temp = new Node(0);
                if (num > 9)
                {
                    num = num % 10;
                    temp->data = num;
                    carry = 1;
                }
                else
                {
                    temp->data = num;
                    carry = 0;
                }
                ans->next = temp;
                ans = ans->next;
                s = s->next;
            }
        }
        else
        {
            while (f != NULL)
            {
                int num = f->data + carry;
                Node *temp = new Node(0);
                if (num > 9)
                {
                    num = num % 10;
                    temp->data = num;
                    carry = 1;
                }
                else
                {
                    temp->data = num;
                    carry = 0;
                }
                ans->next = temp;
                ans = ans->next;
                f = f->next;
            }
        }

        if (carry == 1)
        {
            Node *temp = new Node(1);
            ans->next = temp;
            ans = ans->next;
        }

        Node *result = reverse(res->next);

        return result;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;

        cin >> n;
        Node *first = buildList(n);

        cin >> m;
        Node *second = buildList(m);
        Solution ob;
        Node *res = ob.addTwoLists(first, second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends