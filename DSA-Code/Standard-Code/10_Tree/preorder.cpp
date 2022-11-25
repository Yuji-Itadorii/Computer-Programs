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

void preorder(node * root){
    if(root!= NULL){
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}


int main(){

    node * root = new node(10);
    root->left = new node(20);
    root->right  = new node(30);

    cout<<"Inorder travesal of tree is :-"<<endl;
    preorder(root);

    
    return 0;
}