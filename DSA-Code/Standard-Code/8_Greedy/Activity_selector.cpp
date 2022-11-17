#include<bits/stdc++.h>
using namespace std;

bool mycomp( pair<double , double> a , pair<double , double> b){
    return (a.second < b.second);
}

vector <pair <double , double> >  maxClasses(pair<double , double> p[] , int n){
    vector <pair<double , double> > res;
    sort(p , p+n , mycomp);
    int prev = 0;
    res.push_back(p[0]);
    for (int i = 1; i < n; i++)
    {
        if(p[i].first >= p[prev].second){
            res.push_back(p[i]);
            prev = i;
        }
    }

    return res;
    
}

int main(){
    int n = 5;
    pair < double , double> p[5] = {{9 , 10} , { 9.30 , 10.30} , {10 , 11} , {10.30 , 11.30} , {11 , 12}};

    vector<pair<double , double> > res = maxClasses(p , n);

    for (int i = 0; i < res.size(); i++)
    {
        cout<<res[i].first<<"-"<<res[i].second<<endl;
    }
    
    return 0;
}