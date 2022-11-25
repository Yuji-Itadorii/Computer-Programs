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


int main(){

    node * root = new node(10);
    root->left = new node(20);
    root->right  = new node(30);

    cout<<"Root is :- "<<root->key<<endl;
    cout<<"Root's left value is :- "<<root->left->key<<endl;
    cout<<"Root's right value is :- "<<root->right->key<<endl;

    
    return 0;
}