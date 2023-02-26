// Question : - https://practice.geeksforgeeks.org/problems/find-the-string-in-grid0111/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> res;
    bool solve (int idx, int dir, int i, int j, vector<vector<char>>&grid, string word) {
        if(!(i>=0 && j>=0 && i<grid.size() && j<grid[0].size()))
            return false;
        if(word[idx]!=grid[i][j]) return false;
        if(idx == word.length()-1) return true;
        
        if(dir == 0) {
            // move in all eight directions
    return  solve(idx+1, 1, i, j+1, grid, word) ||
            solve(idx+1, 2, i-1, j+1, grid, word) || 
            solve(idx+1, 3, i-1, j, grid, word) || 
            solve(idx+1, 4, i-1, j-1, grid, word) ||
            solve(idx+1, 5, i, j-1, grid, word) ||
            solve(idx+1, 6, i+1, j-1, grid, word) ||
            solve(idx+1, 7, i+1, j, grid, word) ||
            solve(idx+1, 8, i+1, j+1, grid, word);
        } 
        else {
            if(dir == 1) 
                return solve(idx+1, 1, i, j+1, grid, word);
            else if(dir == 2)
                return solve(idx+1, 2, i-1, j+1, grid, word);
            else if(dir == 3)
                return solve(idx+1, 3, i-1, j, grid, word);
            else if(dir == 4)
                return solve(idx+1, 4, i-1, j-1, grid, word);
            else if(dir == 5)
                return solve(idx+1, 5, i, j-1, grid, word);
            else if(dir == 6)
                return solve(idx+1, 6, i+1, j-1, grid, word);
            else if(dir == 7) 
                return solve(idx+1, 7, i+1, j, grid, word);
            else if(dir == 8)
                return solve(idx+1, 8, i+1, j+1, grid, word);
        }
        
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    int n = grid.size(); int m = grid[0].size();
	    for(int i=0; i<n; i++)
	        for(int j=0; j<m; j++) 
                if(solve(0, 0, i, j, grid, word)) 
                    res.push_back({i, j});
        
        return res;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends