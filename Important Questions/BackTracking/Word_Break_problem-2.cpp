// https://practice.geeksforgeeks.org/problems/word-break-part-23249/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    struct Node
    {
        Node *child[26];
        int isLeaf;

        Node()
        {
            for (int i = 0; i < 26; i++)
            {
                child[i] = NULL;
            }
            isLeaf = 0;
        }
    };

    void insert(Node *root, string &key)
    {
        for (int i = 0; i < key.size(); i++)
        {
            if (root->child[key[i] - 'a'] == NULL)
            {
                root->child[key[i] - 'a'] = new Node();
            }

            root = root->child[key[i] - 'a'];
        }

        root->isLeaf++;
    }

    void solve(int i, Node *root, string &s, vector<string> &res, string temp)
    {
        if (i >= s.size())
        {
            temp.pop_back();
            res.push_back(temp);
            return;
        }
        string a = "";
        Node *p = root;
        for (int j = i; j < s.size(); j++)
        {
            if (p->child[s[j] - 'a'] == NULL)
                return;
            p = p->child[s[j] - 'a'];
            a += s[j];
            if (p->isLeaf)
            {
                string t = temp;
                temp += a + " ";
                solve(j + 1, root, s, res, temp);
                temp = t;
            }
        }
    }

    vector<string> wordBreak(int n, vector<string> &dict, string s)
    {
        // code here
        Node *root = new Node();

        for (auto x : dict)
        {
            insert(root, x);
        }

        vector<string> res;
        solve(0, root, s, res, "");
        return res;
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
        vector<string> dict;
        string s;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            dict.push_back(s);
        }
        cin >> s;

        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if (ans.size() == 0)
            cout << "Empty\n";
        else
        {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++)
                cout << "(" << ans[i] << ")";
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends