// https://leetcode.com/problems/next-greater-element-ii/submissions/991948399/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();

        vector<int> res(n);
        
        for(int i = 2*n-1 ; i>=0 ; i--){
            while(!st.empty() && arr[i%n]>=st.top()){
                st.pop();
            }

            if(i<n){
                res[i] = (st.empty())? -1 : st.top();
            }

            st.push(arr[i%n]);
        }

        return res;
    }
};

int main(){
    
    return 0;
}