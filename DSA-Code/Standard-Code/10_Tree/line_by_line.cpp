#include<bits/stdc++.h>
using namespace std;

struct node {
    int key;
    node * left , *right;
    node(){
        key = 0 ;
        left = NULL;
        right = NULL;
    }
    node(int x){
        key = x ;
        left = NULL;
        right = NULL;
    }
};

void lineByLine(node *root){
    if(root == NULL){
        return;
    }

    queue <node *> q;
    q.push(root);
    q.push(NULL);
    while (q.size() > 1)
    {
        node * curr = q.front();
        q.pop();
        if(curr == NULL){
            cout<<endl;
            q.push(NULL);
            continue;
        }
        cout<<curr->key<<" ";
        if(curr->left != NULL) q.push(curr->left);
        if(curr->right != NULL) q.push(curr->right);
    }
    
}


int main(){

    node * root = new node(10);
    root->left = new node(20);
    root->left->right  = new node(30);

    // tree is like :- 

    //      10
    //     /
    //    20
    //     \
    //      30

    cout<<"Line by line traversal : -"<< endl;
    lineByLine(root); 

    

    
    return 0;
}