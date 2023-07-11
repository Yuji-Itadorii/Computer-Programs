// https://practice.geeksforgeeks.org/problems/special-stack/1

//{ Driver Code Starts
#include <iostream>
#include <stack>
using namespace std;
void push(stack<int> &s, int a);
bool isFull(stack<int> &s, int n);
bool isEmpty(stack<int> &s);
int pop(stack<int> &s);
int getMin(stack<int> &s);
// This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a;
        cin >> n;
        while (!isEmpty(s))
        {
            pop(s);
        }
        while (!isFull(s, n))
        {
            cin >> a;
            push(s, a);
        }
        cout << getMin(s) << endl;
    }
}
// } Driver Code Ends

int mini = 100000;
void push(stack<int> &s, int a)
{
    // Your code goes here
    if (s.empty())
    {
        mini = a;
        s.push(a);
    }
    else if (a <= mini)
    {
        s.push(2 * a - mini);
        mini = a;
    }
    else
    {
        s.push(a);
    }
}

bool isFull(stack<int> &s, int n)
{
    // Your code goes here
    return s.size() == n;
}

bool isEmpty(stack<int> &s)
{
    // Your code goes here
    return s.empty();
}

int pop(stack<int> &s)
{
    // Your code goes here
    int t = s.top();
    s.pop();
    if (t <= mini)
    {
        int res = mini;
        mini = 2 * mini - t;
        return res;
    }
    else
    {
        return t;
    }
}

int getMin(stack<int> &s)
{
    // Your code goes here
    return mini;
}