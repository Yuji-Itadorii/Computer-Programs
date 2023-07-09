// https://www.spoj.com/problems/ARRANGE/

#include<bits/stdc++.h>
#define int             long long int
#define pb              push_back
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mod             1000000007
#define w(x)            int x; cin>>x; while(x--)
using namespace std;
 
int32_t main() {
   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        int ones = 0;
        for(int i=0;i<n;i++) {
            cin>>a[i];
            if(a[i]==1) ones++;
        }
        sort(a,a+n,greater<int>());
        for(int i=0;i<ones;i++) cout<<"1 ";
            
        if((n-ones)==2 and a[0]==3 and a[1]==2){
            cout<<"2 3"<<endl;
        }
        else{
            for(int i=0;i<(n-ones);i++) cout<<a[i]<<" ";
            cout<<endl;
        }
    }
    
    return 0;
}