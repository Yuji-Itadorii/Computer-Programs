// https://practice.geeksforgeeks.org/problems/87f12e5c728d69a5322634776b54c75897d14daa/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
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

void push(struct Node **head_ref, int new_data)
{

    struct Node *new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int countTriplets(struct Node *head, int x);

/* Driver program to test count function*/
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, i, num;
        struct Node *head = NULL;
        cin >> n >> x;
        for (i = 0; i < n; i++)
        {
            cin >> num;
            push(&head, num);
        }

        /* Check the count function */
        cout << countTriplets_using_hashing(head, x) << endl;
    }
    return 0;
}
// } Driver Code Ends

// User function Template for C++



//User function Template for C++

int countTriplets_using_pointers(struct Node* head, int x) 
{ 
    // code here.
    vector<int> A;
    Node*curr = head;
    while(curr!=NULL){
        A.push_back(curr->data);
        curr = curr->next;
    }
    
    sort(A.begin() , A.end());
    
    int count =0;
    for (int i = 0; i < A.size()- 2; i++)
    {
        int l = i + 1;
        int r = A.size() - 1;
        while (l < r) {
            int sum = A[i] + A[l] + A[r]; 
            // cout<<sum<<" "<<i<<" "<<l<<" "<<r<<endl;
            if (sum== x) {
                count++;
                l++;
                r--;
            }
            else if (sum>x){
                r--;
            }
            else{
                l++;
            }
        }
    }
    
    return count;
} 

int countTriplets_using_hashing(struct Node *head, int sum)
{
    // code here.

    int count = 0;
    for (auto x = head; x->next->next != NULL; x = x->next)
    {
        if (x->data >= sum)
        {
            continue;
        }
        unordered_set<int> s;
        int curr_sum = sum;
        curr_sum = curr_sum - x->data;
        for (auto y = x->next; y != NULL; y = y->next)
        {
            if (y->data >= curr_sum)
            {
                continue;
            }
            if (s.find(curr_sum - y->data) != s.end())
            {
                count++;
            }

            s.insert(y->data);
        }
    }

    return count;
}