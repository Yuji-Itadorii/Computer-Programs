// https://practice.geeksforgeeks.org/problems/minimum-swap-required-to-convert-binary-tree-to-binary-search-tree/0?page=1&sortBy=newest&query=page1sortBynewest

//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
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

class Solution
{
public:
    Node *make_tree(vector<int> &v, int i, int n)
    {

        Node *root = NULL;

        if (i < n)
        {

            root = new Node(v[i]);

            root->left = make_tree(v, 2 * i + 1, n);
            root->right = make_tree(v, 2 * i + 2, n);
        }

        return root;
    }

    void inorder(Node *root, vector<int> &v)
    {
        if (root == NULL)
        {
            return;
        }

        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }

    int minSwaps(vector<int> &A, int n)
    {

        Node *root = make_tree(A, 0, n);
        vector<int> v;
        inorder(root, v);

        vector<pair<int, int>> p;

        for (int i = 0; i < n; i++)
        {
            p.push_back({v[i], i});
        }

        sort(p.begin(), p.end());
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (i == p[i].second)
            {
                continue;
            }
            else
            {
                count++;
                swap(p[i], p[p[i].second]);
                i--;
            }
        }

        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        Solution ob;
        int ans = ob.minSwaps(A, n);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends