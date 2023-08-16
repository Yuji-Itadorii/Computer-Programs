// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        if (head == NULL)
        {
            return head;
        }

        if (head->next == NULL and n == 1)
        {
            return NULL;
        }

        ListNode *fast = head, *slow = head;

        for (int i = 0; i < n; i++)
            fast = fast->next;
        if (!fast)
            return head->next;
        while (fast->next)
            fast = fast->next, slow = slow->next;
        slow->next = slow->next->next;
        return head;
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        // code
    }
    return 0;
}