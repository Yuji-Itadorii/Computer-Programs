#include<bits/stdc++.h>
using namespace std;

bool mycomp( pair<int , int> a , pair<int , int> b){
    
    return (a.first > b.first);
}

double knapSack(pair<int , int> p[] , int n , int w){
    double res = 0;
    sort(p , p+n , mycomp);


    for (int i = 0; i < n; i++)
    {
        if(p[i].second <= w){
            res += p[i].first;
            w -= p[i].second;
        }
    }
    return res;
    
}

int main(){
    int n = 3;
    pair < int , int> p[5] = {{600 , 50} , { 500 , 20} , {400 , 30}};
    int w = 70;

    cout<<knapSack(p , n ,w);
    
    return 0;
}