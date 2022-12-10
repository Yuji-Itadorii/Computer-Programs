#include<bits/stdc++.h>
using namespace std;
struct Node{
 int freq;
 char c;
 Node * left , *right;

 Node(int f , char ch , Node * l = NULL , Node * r = NULL){
    freq = f;
    c = ch;
    left = l;
    right = r;
 }
};

struct compare
{
    bool operator()(Node *l , Node*r){
        return l->freq > r->freq;
    }
};

void printCodes( Node* root, string str)
{

	if (!root)
		return;

	if (root->c != '$')
		cout << root->c << ": " << str << "\n";

	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}


void printHcodes(char arr[] , int frequence[] , int n){
    priority_queue<Node*, vector<Node*>, compare> h;
    for(int i = 0 ; i< n ; i++){
        h.push(new Node(frequence[i] , arr[i]));
    }

    while (h.size() >1)
    {
        Node *l = h.top() ; h.pop();
        Node *r = h.top() ; h.pop();
        Node *n = new Node ((l->freq+r->freq) , '$' , l ,r);
        h.push(n);
    }
    
    printCodes(h.top() , "" );
}



int main(){
    char arr[] =      { 'A' , 'B' , 'C' , 'D' , 'E' , 'F' , 'G' , 'H'};
    int frequence[] = { 22,    5,   11,   19,    2,    11,   25,   5 };
    int size = sizeof(arr) / sizeof(arr[0]);
    printHcodes(arr, frequence ,size);
    return 0;
}