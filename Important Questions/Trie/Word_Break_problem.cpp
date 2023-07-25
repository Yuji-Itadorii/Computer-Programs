// https://practice.geeksforgeeks.org/problems/d857113143f69fab217cf5dab978535542f3cbb1/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
struct node
{
    node *child[26];
    bool isEnd;
    node()
    {
        for (int i = 0; i < 26; i++)
        {
            child[i] = NULL;
            isEnd = false;
        }
    }
};
void insert(node *root, string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (root->child[s[i] - 'a'])
            root = root->child[s[i] - 'a'];
        else
        {
            root->child[s[i] - 'a'] = new node();
            root = root->child[s[i] - 'a'];
        }
    }
    root->isEnd = true;
}

bool search(node *root, string A)
{
    int n = A.length();
    node *temp = root;

    for (int i = 0; i < n; i++)
    {
        if (!temp->child[A[i] - 'a'])
            return false;
        temp = temp->child[A[i] - 'a'];
    }

    return (temp && temp->isEnd);
}
class Solution
{
public:
    // A : given string to search
    // B : vector of available strings

    bool solve(node *root, string s)
    {
        int n = s.length();
        if (n == 0)
            return true;
        for (int i = 1; i <= n; i++)
        {
            if (search(root, s.substr(0, i)) && solve(root, s.substr(i, n - i)))
                return true;
        }
        return false;
    }

    int wordBreak(string A, vector<string> &B)
    {
        // code here
        node *root = new node();

        for (auto it : B)
            insert(root, it);

        return solve(root, A);
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
        vector<string> dict;
        for (int i = 0; i < n; i++)
        {
            string S;
            cin >> S;
            dict.push_back(S);
        }
        string line;
        cin >> line;
        Solution ob;
        cout << ob.wordBreak(line, dict) << "\n";
    }
}

// } Driver Code Ends