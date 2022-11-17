#include<bits/stdc++.h>
using namespace std;

void add_Edge(vector<int> adj[] , int u , int v){
    adj[u].push_back(v);
    // adj[v].push_back(u);
}

void print_Graph(vector<int> adj[] , int V){
    for (int i = 0; i < V; i++)
    {
        cout<<i<<"->";
        for (int x : adj[i])
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}

void topological_BFS( vector<int> adj[] , int V){
    vector <int> indegree(V , 0);
    for (int i = 0; i < V; i++)
    {
        for(int x : adj[i]){
            indegree[x]++;
        }
    }

    queue <int> q ;
    for(int i = 0 ; i< indegree.size() ; i++){
        if(indegree[i] == 0)
            q.push(i);
    }

    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();
        cout<<u<<" ";
        for (int x : adj[u])
        {
            if(--indegree[x] == 0){
                q.push(x);
            }
        }
        
    }
    
    
}


int main(){

    int V = 6 ;

    vector <int> adj[V]; 

    add_Edge(adj , 5, 0);
    add_Edge(adj , 5, 2);
    add_Edge(adj , 4, 1);
    add_Edge(adj , 4, 0);
    add_Edge(adj , 2, 3);
    add_Edge(adj , 3, 1);

    print_Graph(adj , V);

    topological_BFS(adj , V);
    
    return 0;
}