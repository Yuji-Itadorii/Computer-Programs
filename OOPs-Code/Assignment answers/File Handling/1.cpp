#include <iostream>
#include <dirent.h>
#include <fstream>
#include <sys/types.h>
#include <string>
#include <cstring>
using namespace std;

struct node
{
    string data;
    node *next;
    node()
    {
        next = NULL;
    };
    node(string d)
    {
        data = d;
        next = NULL;
    }
};

bool checkTXTfile(string fn)
{
    if (fn.substr(fn.find_last_of(".") + 1) == "txt")
    {
        return true;
    }
    else
    {
        return false;
    }
}

node *addNode(node *head, char *s)
{
    if (checkTXTfile(s))
    {
        node *newNode = new node(s);
        if (head == NULL)
        {
            return newNode;
        }
        newNode->next = head;
        head = newNode;
        return head;
    }
    else
    {
        return head;
    }
}

void printList(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

void copystring(char str[20] , node * temp){
    for (int i = 0; i < temp->data.size(); i++)
    {
        str[i] = temp->data[i];
    }
}

int main(void)
{
    node *head;
    DIR *d;
    struct dirent *dir;
    d = opendir("D:\\Github Repo\\Programs\\OOPs-Code\\Assignment answers\\File Handling\\Files");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            head = addNode(head, dir->d_name);
        }
        closedir(d);
    }

    printList(head);

 

    return 0;
}