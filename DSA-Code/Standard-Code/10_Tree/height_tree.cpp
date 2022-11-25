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

int height(node * root){
    if(root == NULL){
        return 0;
    }

    return max(height(root->left) , height(root->right)) +1;
}


int main(){

    node * root = new node(10);
    root->left = new node(20);
    root->right  = new node(30);

    cout<<"The height of tree is :- "<<height(root)<<endl;

    
    return 0;
}