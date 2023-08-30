// https://leetcode.com/problems/odd-even-linked-list/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

//  * Definition for singly-linked list.
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
    ListNode *oddEvenList(ListNode *head)
    {
        ListNode *es = NULL;
        ListNode *eE = NULL;
        ListNode *os = NULL;
        ListNode *oE = NULL;
        bool flag = true;
        for (ListNode *curr = head; curr != NULL; curr = curr->next)
        {
            if (flag)
            {
                if (es == NULL)
                {
                    es = curr;
                    eE = es;
                }
                else
                {
                    eE->next = curr;
                    eE = eE->next;
                }
                flag = false;
            }
            else
            {
                if (os == NULL)
                {
                    os = curr;
                    oE = os;
                }
                else
                {
                    oE->next = curr;
                    oE = oE->next;
                }
                flag = true;
            }
        }

        if (os == NULL || es == NULL)
        {
            return head;
        }
        eE->next = os;
        oE->next = NULL;
        return es;
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