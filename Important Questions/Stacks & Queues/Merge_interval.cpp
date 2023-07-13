// https://practice.geeksforgeeks.org/problems/8a644e94faaa94968d8665ba9e0a80d1ae3e0a2d/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& arr) {
         // Code here
         if(arr.size() == 1){
             return arr;
         }
         
         sort(arr.begin() , arr.end());
         int n = arr.size();
         
        vector<vector<int>> res;
        res.push_back(arr[0]);
        for(int i = 1 ; i< arr.size() ; i++){
            if(res.back()[1] < arr[i][0]){
               res.push_back(arr[i]);
            }
            else{
                res.back()[1] = max(res.back()[1], arr[i][1]);
            }
        }

        return res;
         
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends