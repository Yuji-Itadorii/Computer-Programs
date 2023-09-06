// https://leetcode.com/problems/split-linked-list-in-parts/submissions/?envType=daily-question&envId=2023-09-06

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    vector<ListNode *> splitListToParts(ListNode *root, int k)
    {
        vector<ListNode *> parts(k, nullptr);
        int len = 0;
        for (ListNode *node = root; node; node = node->next)
            len++;

        int n = len / k, r = len % k;
        ListNode *node = root, *prev = nullptr;
        for (int i = 0; node && i < k; i++, r--)
        {
            parts[i] = node;
            for (int j = 0; j < n + (r > 0); j++)
            {
                prev = node;
                node = node->next;
            }
            prev->next = nullptr;
        }
        return parts;
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        Solution ob;
    }
    return 0;
}