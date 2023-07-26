// https://practice.geeksforgeeks.org/problems/unique-rows-in-boolean-matrix/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col);

// } Driver Code Ends

struct TrieNode
{
    struct TrieNode *children[2];

    // isLeaf is true if the node represents
    // end of a word
    int isLeaf;

    TrieNode()
    {
        for (int i = 0; i < 2; i++)
        {
            children[i] = NULL;
        }

        isLeaf = 0;
    }
};

void insert(struct TrieNode *root, vector<int> &key)
{
    // code here
    for (int i = 0; i < key.size(); i++)
    {
        if (root->children[key[i]] == NULL)
        {
            TrieNode *temp = new TrieNode();
            root->children[key[i]] = temp;
        }

        root = root->children[key[i]];
    }

    root->isLeaf++;
}

// Function to use TRIE data structure and search the given string.
int search(struct TrieNode *root, vector<int> &key)
{
    // code here
    for (int i = 0; i < key.size(); i++)
    {
        if (root->children[key[i]] == NULL)
        {
            return false;
        }

        root = root->children[key[i]];
    }

    return root->isLeaf;
}

class Solution
{
public:
    // #define MAX 1000
    vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col)
    {
        // Your code here
        vector<vector<int>> ans;
        TrieNode *root = new TrieNode();
        for (int i = 0; i < row; i++)
        {
            vector<int> temp;
            for (int j = 0; j < col; j++)
            {
                temp.push_back(M[i][j]);
            }
            insert(root, temp);

            if (search(root, temp) == 1)
            {
                ans.push_back(temp);
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        int a[MAX][MAX];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        Solution ob;
        vector<vector<int>> vec = ob.uniqueRow(a, n, m);
        for (int i = 0; i < vec.size(); i++)
        {
            for (int x : vec[i])
            {
                cout << x << " ";
            }
            cout << "$";
        }
        cout << endl;
    }
}

// } Driver Code Ends