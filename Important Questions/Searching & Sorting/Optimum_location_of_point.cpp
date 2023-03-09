// https://practice.geeksforgeeks.org/problems/optimum-location-of-point-to-minimize-total-distance/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article



//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    
    double calc_dist(vector<pair<int,int>>& p,int n,tuple<int,int,int>& line,double x){
       double a = get<0>(line);
       double b = get<1>(line);
       double c = get<2>(line);
       double y = -1*(c+(a*x))/b;
       double dist = 0;
       for(int i=0;i<n;++i){
           double x1 = p[i].first;
           double y1 = p[i].second;
           dist += sqrt((x1-x)*(x1-x) + (y1-y)*(y1-y));
       }
       return dist;
   }
    
    
    double findOptimumCost(tuple<int,int,int>line, vector<pair<int,int>>p, int n){
	    //Write your code here
	   double l;
	   double r;
       l = -1000;
       r = 1000;
       double mid1,mid2;
       while(r-l>0.0000001){
           mid1 = l+(r-l)/3;
           mid2 = r-(r-l)/3;
           
           double fmid1 = calc_dist(p,n,line,mid1);
           double fmid2 = calc_dist(p,n,line,mid2);
           
           if(fmid1>fmid2){
               l = mid1;
           } else if(fmid1<fmid2){
               r=mid2;
           } else{
               l = mid1;
               r = mid2;
           }
       }
       
       return calc_dist(p,n,line,r);
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    tuple<int,int,int>line;
	    int a, b, c;
	    cin >> a >> b >> c;
	    line = make_tuple(a, b, c);
	    int n;
	    cin >> n;
	    vector<pair<int,int>>points;
	    for(int i = 0 ; i < n; i++){
	        int x, y;
	        cin >> x >> y;
	        points.push_back({x, y});
	    }

	    Solution ob;
	    double ans = ob.findOptimumCost(line, points, n);

	    cout << fixed << setprecision(2) << ans << endl;
	}
	return 0;
}

// } Driver Code Ends