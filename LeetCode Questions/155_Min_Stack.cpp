// https://leetcode.com/problems/min-stack/description/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

class MinStack
{
private:
    vector<pair<int, int>> s;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        if (s.empty())
            s.push_back({val, val});
        else
            s.push_back({val, min(s.back().second, val)});
    }

    void pop()
    {
        s.pop_back();
    }

    int top()
    {
        return s.back().first;
    }

    int getMin()
    {
        return s.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        MinStack *obj = new MinStack();
        obj->push(10);
        obj->push(20);
        obj->push(30);
        obj->push(40);
        obj->push(50);
        obj->push(60);
        obj->push(70);
        obj->push(80);
        obj->push(90);

        cout << obj->top() << endl;
        cout << obj->getMin() << endl;
        obj->pop();
        cout << obj->top() << endl;
        cout << obj->getMin() << endl;
        obj->pop();
        cout << obj->top() << endl;
        cout << obj->getMin() << endl;
        obj->pop();

        cout << obj->top() << endl;
        cout << obj->getMin() << endl;
        obj->pop();
        cout << obj->top() << endl;
        cout << obj->getMin() << endl;
        obj->pop();
        cout << obj->top() << endl;
        cout << obj->getMin() << endl;
        obj->pop();
        cout << obj->top() << endl;
        cout << obj->getMin() << endl;
        obj->pop();
        cout << obj->top() << endl;
    }
    return 0;
}