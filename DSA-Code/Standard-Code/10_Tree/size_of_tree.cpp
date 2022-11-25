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

int sizeOfTree(node * root){
    if(root == NULL){
        return 0;
    }

    return sizeOfTree(root->left) + sizeOfTree(root->right) +1;
}


int main(){

    node * root = new node(10);
    root->left = new node(20);
    root->right  = new node(30);

    cout<<"The height of tree is :- "<<sizeOfTree(root)<<endl;

    
    return 0;
}