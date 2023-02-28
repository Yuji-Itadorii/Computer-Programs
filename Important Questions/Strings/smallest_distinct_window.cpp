// https://practice.geeksforgeeks.org/problems/smallest-distant-window3132/1

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here  
        int n = str.size();
        unordered_map<char,int> m , p;
        for(int i =0; i< n ; i++){
            m[str[i]]++;
        }
        
        int req_size = m.size();
        for(int i =0 ; i< req_size ; i++){
            p[str[i]]++;
        }
        int window_size = req_size;
        // cout<<window_size<<endl;
        
        
        int idx = 0;
        int res = n;
        
        if(p.size() == req_size){
            res = p.size();    
        }
        
        for(int i = req_size ; i<n ;  i++){
            
            p[str[i]]++;
            window_size++;
            
            if(p.size() == req_size){
                while(p[str[idx]]>1){
                    window_size--;
                    p[str[idx]]--;
                    idx++;
                }
                res = min(res,window_size);
            }

            
        }
        
        return res;
       
    }
};

int main(){
    
    return 0;
}