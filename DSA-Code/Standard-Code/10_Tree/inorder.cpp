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

void inorder(node * root){
    if(root!= NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}


int main(){

    node * root = new node(10);
    root->left = new node(20);
    root->right  = new node(30);

    cout<<"Inorder travesal of tree is :-"<<endl;
    inorder(root);

    
    return 0;
}