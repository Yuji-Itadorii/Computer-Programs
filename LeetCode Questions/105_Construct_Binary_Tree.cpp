// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{

private:
    int preIndex = 0;

    TreeNode *solve(vector<int> &pre, vector<int> &in, int s, int e)
    {
        if (s > e)
        {
            return NULL;
        }

        TreeNode *root = new TreeNode(pre[preIndex++]);

        int inIndex;
        for (int i = s; i <= e; i++)
        {
            if (in[i] == root->val)
            {
                inIndex = i;
            }
        }

        root->left = solve(pre, in, s, inIndex - 1);
        root->right = solve(pre, in, inIndex + 1, e);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = preorder.size();
        TreeNode *root = solve(preorder, inorder, 0, n - 1);
        return root;
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        Solution s;
        vector<int> preorder = {3, 9, 20, 15, 7};
        vector<int> inorder = {9, 3, 15, 20, 7};
        TreeNode *root = s.buildTree(preorder, inorder);

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            cout << temp->val << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        cout << endl;
        }
    return 0;
}