#include<bits/stdc++.h>
using namespace std;
const int V = 5;

void add_Edge(vector<int> G[] , int v , int u){
    G[u].push_back(v);
    G[v].push_back(u);
}

void print_Graph(vector<int> G[] , int V){
    for (int i = 0; i < V; i++)
    {
        cout<<i<<"->";
        for (int x : G[i])
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}


vector<int> primMst_weight( int weight[V][V] , vector<int> adj[] , int s){
    vector<int> key(V);
    vector<int> predecessor(V);
    vector<bool> mSet(V);

    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        predecessor[i] = -1;
        mSet[i] = false; 
    }

    key[s] = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i =0 ; i<V ; i++){
        pq.push(i);
    }

    while (pq.empty() == false)
    {
        int u = pq.top();
        pq.pop();
        mSet[u] = true;
        for(int v : adj[u]){
            if(mSet[v] == false && weight[u][v]<key[v]){
                predecessor[v] = u;
                key[v] = weight[u][v];
            }
        }
    }
    
    return predecessor;
    
}

int main(){

    
    
     int weight[V][V] = { { 0, 2, 0, 6, 0 },
                          { 2, 0, 3, 8, 5 },
                          { 0, 3, 0, 0, 7 },
                          { 6, 8, 0, 0, 9 },
                          { 0, 5, 7, 9, 0 } };

    vector <int> adj[V];

    add_Edge(adj , 0 , 1);
    add_Edge(adj , 0 , 3);
    add_Edge(adj , 1 , 2);
    add_Edge(adj , 1 , 3);
    add_Edge(adj , 1 , 4);
    add_Edge(adj , 2 , 4);
    add_Edge(adj , 3 , 4);

    // print_Graph(adj , V);

    vector<int> res = primMst_weight(weight , adj , 0);
    
    for(int i = 0 ; i< res.size() ; i++){
        cout<<i<<"->"<<res[i]<<endl;
    }

    return 0;
}