// https://leetcode.com/problems/lru-cache/submissions/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

struct node
{
    int key;
    int val;
    node *prev;
    node *next;

    node(int k, int v)
    {
        key = k;
        val = v;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache
{
public:
    unordered_map<int, node *> mp;
    int capacity;
    node *head = new node(0, 0);
    node *tail = new node(0, 0);

    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end())
        {
            return -1;
        }

        node *currnode = mp[key];
        remove(currnode);
        insert(currnode);
        return currnode->val;
    }

    void remove(node *currnode)
    {
        mp.erase(currnode->key);
        currnode->next->prev = currnode->prev;
        currnode->prev->next = currnode->next;
    }

    void insert(node *currnode)
    {
        currnode->next = head->next;
        head->next->prev = currnode;
        head->next = currnode;
        currnode->prev = head;
        mp[currnode->key] = currnode;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            remove(mp[key]);
        }
        if (mp.size() == capacity)
        {
            remove(tail->prev);
        }
        insert(new node(key, value));
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}