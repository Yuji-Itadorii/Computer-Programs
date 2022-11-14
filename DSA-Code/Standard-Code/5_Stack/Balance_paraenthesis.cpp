#include<iostream>
#include<stack>
using namespace std;

bool matching(char a , char b){
    return (a=='(' &&  b==')'  ||a=='[' &&  b==']' || a=='{' &&  b=='}'  );
}

bool balanceParaenthesis(string &str){
    stack<char> s;
    for(int i = 0 ; i< str.size() ; i++){
        if(str[i] == '(' || str[i] == '{' || str[i] == '['){
            s.push(str[i]);
        }
        else{
            if(s.empty() != false){
                return false;
            }
            if (matching(s.top() , str[i])==false)
            {
                return false;
            }
            else{
                s.pop();
            }
        }
    }
}

int main(){
    string str ; 
    cout<<"Enter thr string of paranthesis :-"<<endl;
    cin>>str;
    if(balanceParaenthesis(str)){
        cout<<"Yes\n";
    }
    else{
        cout<<"No!";
    }
    return 0;
}