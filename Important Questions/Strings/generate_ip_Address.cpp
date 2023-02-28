// https://practice.geeksforgeeks.org/problems/generate-ip-addresses/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article


//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  
    bool isValid(string ip){
       // Splitting by "."
    vector<string> ips;
    string ex = "";
    for (int i = 0; i < ip.size(); i++) {
        if (ip[i] == '.') {
            ips.push_back(ex);
            ex = "";
        }
        else {
            ex = ex + ip[i];
        }
    }
    ips.push_back(ex);
 
    // Checking for the corner cases
    // cout << ip << endl;
    for (int i = 0; i < ips.size(); i++) {
        // cout << ips[i] <<endl;
        if (ips[i].length() > 3
            || stoi(ips[i]) < 0
            || stoi(ips[i]) > 255)
            return 0;
 
        if (ips[i].length() > 1
            && stoi(ips[i]) == 0)
            return 0;
 
        if (ips[i].length() > 1
            && stoi(ips[i]) != 0
            && ips[i][0] == '0')
            return 0;
    }
    return 1;
    }
  
    vector<string> genIp(string &s) {
        // Your code here
        vector<string> res;
        if(s.length() > 12 || s.length() < 4){
            res.push_back("-1");
            return res;
        }
        string check = s;
        int n = s.size();
        
        for(int i =1 ; i<n-2 ; i++){
            for(int j =i+1 ; j<n-1; j++){
                for(int k = j+1 ; k<n ; k++){
                    check = check.substr(0,k)+"."+check.substr(k);
                    check = check.substr(0,j)+"."+check.substr(j);
                    check = check.substr(0,i)+"."+check.substr(i);
                    
                    if(isValid(check)){
                        // cout<<check<<endl;
                        res.push_back(check);
                    }
                    check = s;
                }
            }
            
        }
        
        return res;
    }

};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}
// } Driver Code Ends