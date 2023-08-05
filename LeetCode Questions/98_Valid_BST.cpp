// https://leetcode.com/problems/validate-binary-search-tree/description/

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
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
public:
    bool isValidBST(TreeNode *root)
    {
        if (root == NULL)
            return true;

        stack<TreeNode *> s;
        TreeNode *pre = NULL;
        while (root != NULL || !s.empty())
        {
            while (root != NULL)
            {
                s.push(root);
                root = root->left;
            }

            root = s.top();
            s.pop();
            if (pre != NULL && root->val <= pre->val)
                return false;
            pre = root;
            root = root->right;
        }

        return true;
    }
};

int main()
{

    return 0;
}