// https://leetcode.com/problems/implement-trie-prefix-tree/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class TrieNode
{
public:
    TrieNode *child[26];
    bool isWord;
    TrieNode()
    {
        isWord = false;
        for (auto &a : child)
            a = nullptr;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string s)
    {
        TrieNode *p = root;
        for (auto &a : s)
        {
            int i = a - 'a';
            if (!p->child[i])
                p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->isWord = true;
    }

    bool search(string key)
    {
        TrieNode *p = root;
        for (auto &a : key)
        {
            int i = a - 'a';
            if (!p->child[i])
                return false;
            p = p->child[i];
        }

        return p->isWord;
    }

    bool startsWith(string key)
    {
        TrieNode *p = root;
        for (auto &a : key)
        {
            int i = a - 'a';
            if (!p->child[i])
                return false;
            p = p->child[i];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        Trie *obj = new Trie();
        obj->insert("apple");
        cout << obj->search("apple") << endl;
        cout << obj->search("app") << endl;
        cout << obj->startsWith("app") << endl;
        obj->insert("app");
        cout << obj->search("app") << endl;
    }
    return 0;
}