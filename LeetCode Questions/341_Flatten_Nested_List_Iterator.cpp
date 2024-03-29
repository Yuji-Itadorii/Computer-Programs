// https://leetcode.com/problems/flatten-nested-list-iterator/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger
{
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator
{
    queue<int> q;
    void recur(vector<NestedInteger> A)
    {
        for (auto x : A)
            if (x.isInteger())
                q.push(x.getInteger());
            else
                recur(x.getList());
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        recur(nestedList);
    }

    int next()
    {
        auto i = q.front();
        q.pop();
        return i;
    }

    bool hasNext()
    {
        return !q.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
    }
    return 0;
}