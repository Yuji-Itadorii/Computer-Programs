// https://www.spoj.com/problems/DEFKIN/

#include <iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main() {
	int t ;
	 cin>>t;
	 while(t--){
	 	int w , h, n;
	 	cin>>w>>h>>n;
	 	vector<int> a , b;
	 	a.push_back(0);
	 	b.push_back(0);
	 	for(int i =0 ; i< n ; i++){
	 		int x , y;
	 		cin>>x>>y;
	 		a.push_back(x);
	 		b.push_back(y);
	 	}
	 	
	 	sort(a.begin() , a.end());
	 	sort(b.begin() , b.end());
	 	int mx = INT_MIN , my = INT_MIN;
	 	for(int i =0 ; i< a.size()-1 ; i++){
	 		mx = max(mx , a[i+1]-a[i]-1);
	 		my = max(my , b[i+1]-b[i]-1);
	 	}
	 	
	 	cout<<mx*my<<endl;
	 }
	return 0;
}