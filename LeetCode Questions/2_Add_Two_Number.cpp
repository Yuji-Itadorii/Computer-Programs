// https://leetcode.com/problems/add-two-numbers/description/

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        ListNode *root = new ListNode(-1);
        ListNode *dummy = root;

        while (l1 != NULL and l2 != NULL)
        {
            int digit = l1->val + l2->val + carry;

            carry = 0;

            if (digit > 9)
            {
                digit = digit % 10;
                carry = 1;
            }

            ListNode *temp = new ListNode(digit);
            dummy->next = temp;
            dummy = dummy->next;

            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != NULL)
        {

            int digit = l1->val + carry;
            carry = 0;

            if (digit > 9)
            {
                digit = digit % 10;
                carry = 1;
            }

            ListNode *temp = new ListNode(digit);
            dummy->next = temp;
            dummy = dummy->next;

            l1 = l1->next;
        }

        while (l2 != NULL)
        {

            int digit = l2->val + carry;
            carry = 0;

            if (digit > 9)
            {
                digit = digit % 10;
                carry = 1;
            }

            ListNode *temp = new ListNode(digit);
            dummy->next = temp;
            dummy = dummy->next;

            l2 = l2->next;
        }

        if (carry != 0)
        {
            ListNode *temp = new ListNode(carry);
            dummy->next = temp;
        }

        return root->next;
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