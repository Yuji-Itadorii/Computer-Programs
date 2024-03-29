// https://practice.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void insert(Node **tree, int val)
{
    Node *temp = NULL;
    if (!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if (val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if (val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }
}

int getCountOfNode(Node *root, int l, int h)
{

    if (!root)
        return 0;

    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
        return 1 + getCountOfNode(root->left, l, h) +
               getCountOfNode(root->right, l, h);

    else if (root->data < l)
        return getCountOfNode(root->right, l, h);

    else
        return getCountOfNode(root->left, l, h);
}

bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        Node *root;
        Node *tmp;
        // int i;

        root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            int k;
            cin >> k;
            insert(&root, k);
        }

        cout << isDeadEnd(root);
        cout << endl;
    }
}

// } Driver Code Ends

/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
void inorder(Node *root, unordered_set<int> &st)
{
    if (root == NULL)
        return;

    inorder(root->left, st);
    st.insert(root->data);
    inorder(root->right, st);
}

bool check(Node *root, unordered_set<int> &st)
{
    if (root == NULL)
        return false;

    if (root->left == NULL && root->right == NULL)
    {
        int tp = root->data;
        if (st.find(tp - 1) != st.end() && st.find(tp + 1) != st.end())
            return true;
    }
    return (check(root->left, st) || check(root->right, st));
}

bool isDeadEnd(Node *root)
{
    // Your code here
    unordered_set<int> st;
    st.insert(0);
    inorder(root, st);

    return check(root, st);
}