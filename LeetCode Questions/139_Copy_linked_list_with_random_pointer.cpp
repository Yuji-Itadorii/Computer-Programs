// https://leetcode.com/problems/copy-list-with-random-pointer/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {

        unordered_map<Node *, Node *> mp;

        for (Node *curr = head; curr != NULL; curr = curr->next)
        {
            mp[curr] = new Node(curr->val);
        }

        for (Node *curr = head; curr != NULL; curr = curr->next)
        {
            Node *clone = mp[curr];
            clone->next = mp[curr->next];
            clone->random = mp[curr->random];
        }

        return mp[head];
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
    }
    return 0;
}