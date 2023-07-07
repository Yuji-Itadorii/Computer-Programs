// https://practice.geeksforgeeks.org/problems/huffman-encoding3345/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    struct Node
    {
        int freq;
        char c;
        Node *left, *right;

        Node(int f, char ch, Node *l = NULL, Node *r = NULL)
        {
            freq = f;
            c = ch;
            left = l;
            right = r;
        }
    };

    struct compare
    {
        bool operator()(Node *l, Node *r)
        {
            return l->freq > r->freq;
        }
    };

    void Codes(Node *root, string str, vector<string> &res)
    {

        if (!root)
            return;

        if (root->c != '$')
            res.push_back(str);

        Codes(root->left, str + "0", res);
        Codes(root->right, str + "1", res);
    }

    vector<string> huffmanCodes(string S, vector<int> f, int n)
    {
        // Code here
        priority_queue<Node *, vector<Node *>, compare> h;

        for (int i = 0; i < n; i++)
        {
            h.push(new Node(f[i], S[i]));
        }

        while (h.size() > 1)
        {
            Node *l = h.top();
            h.pop();
            Node *r = h.top();
            h.pop();
            Node *n = new Node((l->freq + r->freq), '$', l, r);
            h.push(n);
        }

        vector<string> res;

        Codes(h.top(), "", res);

        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string S;
        cin >> S;
        int N = S.length();
        vector<int> f(N);
        for (int i = 0; i < N; i++)
        {
            cin >> f[i];
        }
        Solution ob;
        vector<string> ans = ob.huffmanCodes(S, f, N);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends