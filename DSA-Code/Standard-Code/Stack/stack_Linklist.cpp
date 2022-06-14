#include <iostream>
#include <climits>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct stack
{
    unsigned size;
    node *head;
    stack()
    {
        head = NULL;
        size = 0;
    }

    bool isEmpty()
    {
        return (head == NULL);
    }

    void push(int x)
    {
        node *temp = new node(x);
        temp->next = head;
        head = temp;
        size++;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Empty\n";
            return INT_MAX;
        }
        node *temp = head;
        int res = head->data;
        head = head->next;
        delete temp;
        size--;
        return res;
    }

    int size_of_stack()
    {
        return (size);
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack Empty\n";
            return INT_MAX;
        }
        return head->data;
    }

    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main()
{
    stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    cout << endl;

    cout << s.size_of_stack() << endl;

    s.pop();


    cout << s.size_of_stack() << endl;

    s.display();

    cout <<endl<< s.peek() << endl;

    return 0;
}