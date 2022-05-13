#include<iostream>
using namespace std;
void PrintFibonaci(int n){
    int nexrTerm = 0 , prev = 1 , secPrev = 0;
    for (int i = 1; i <=n; i++)
    {
        nexrTerm = prev + secPrev ;
        cout<<nexrTerm<<" ";
        secPrev = prev;
        prev = nexrTerm;
    }
    
}
int main(){
    int n;
    cin>>n;
    cout<<"0 1 ";
    PrintFibonaci(n);
    return 0;
}