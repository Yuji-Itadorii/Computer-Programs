#include<bits/stdc++.h>
using namespace std;
const int V = 5;
int parent[V] , Rank[V];

struct Edge{
    int src;
    int des;
    int wei;

    Edge(){
        src = -1;
        des = -1;
        wei = 0;
    }

    Edge(int s , int d , int w ){
        src = s;
        des = d;
        wei = w;
    }
};

bool mycomp(Edge e1 , Edge e2){
    return e1.wei < e2.wei;
}

int find(int x){
    if(x == parent[x]){
        return x;
    }

    parent[x] = find(parent[x]);

    return parent[x];
}

void Union(int x  , int y){
    int x_rep = find(x);
    int y_rep = find(y);

    if(Rank[x] < Rank[y]){
        parent[x_rep] = y_rep;
    }
    else if(Rank[x] > Rank[y]){
        parent[y_rep] = x_rep;
    }
    else{
        parent[y_rep] = x_rep;
        Rank[x_rep]++;
    }
}

void add_Edge(vector<int> G[] , int v , int u , Edge arr[] , int weight[V][V]){
    static int count;
    G[u].push_back(v);
    G[v].push_back(u);
    arr[count].src = u;
    arr[count].des = v;
    arr[count].wei = weight[u][v];
    count++;
}



int kruska_MST( Edge arr[]  , int num_edge){
    sort(arr , arr+num_edge , mycomp);
    for(int i = 0 ; i< V ; i++){
        parent[i] = i;
        Rank[i] = i;
    }

    int res = 0 ;
    for(int i =0 , s=0 ; s<V-1 ; i++){
        Edge e = arr[i];
        int x = find(e.src);
        int y = find(e.des);
        if(x!=y){
            res = res+ e.wei;
            Union(x,y);
            s++;
        }
    }

    return res;

}

int main(){

    
    
     int weight[V][V] = { { 0, 2, 0, 6, 0 },
                          { 2, 0, 3, 8, 5 },
                          { 0, 3, 0, 0, 7 },
                          { 6, 8, 0, 0, 9 },
                          { 0, 5, 7, 9, 0 } };

    vector <int> adj[V];

    int num_edge = 7;
    Edge arr[num_edge];
    static int count = 0;

    add_Edge(adj , 0 , 1, arr , weight);
    add_Edge(adj , 0 , 3, arr , weight);
    add_Edge(adj , 1 , 2, arr , weight);
    add_Edge(adj , 1 , 3, arr , weight);
    add_Edge(adj , 1 , 4, arr , weight);
    add_Edge(adj , 2 , 4, arr , weight);
    add_Edge(adj , 3 , 4, arr , weight);

    // for(int i = 0 ; i< num_edge ; i++){
    //     cout<<arr[i].src<<"->"<<arr[i].des<<"   "<<arr[i].wei<<endl;
    // }

    
    cout<< kruska_MST(arr , num_edge);
    
   
    return 0;
}