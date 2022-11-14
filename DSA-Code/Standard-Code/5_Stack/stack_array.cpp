#include <iostream>
#include <climits>
using namespace std;

struct stack
{
    int top;
    unsigned capacity;
    int *arr;
    stack(unsigned c)
    {
        top = -1;
        capacity = c;
        arr = new int[capacity];
    }

    bool isEmpty()
    {
        return (top == -1);
    }

    bool isFull()
    {
        return (top == capacity - 1);
    }

    void push(int x)
    {
        if (isFull())
        {
            cout << "Stack Overflow\n";
            return;
        }
        top++;
        arr[top] = x;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Empty\n";
            return INT_MAX;
        }
        int res = arr[top];
        top--;
        return res;
    }

    int size()
    {
        return (top + 1);
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack Empty\n";
            return INT_MAX;
        }
        return arr[top];
    }
};

int main()
{
    stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);

    for (int i = 0; i < s.size(); i++)
    {
        cout<<s.arr[i]<<" ";
    }
        cout<<endl;
    

    cout<<s.size()<<endl;

    s.pop();

    cout<<s.size()<<endl;

    cout<<s.peek()<<endl;


    return 0;
}