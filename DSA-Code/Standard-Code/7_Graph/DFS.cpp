#include<bits/stdc++.h>
using namespace std;

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

void DFS_visit( vector<int> G[] , int s , bool visited[] ){
    visited[s] = true;
    cout<<s<<" ";
    for ( int u : G[s])
    {
        if(visited[u] == false){
            DFS_visit(G , u , visited);
        }
    }
    
}

void DFS(vector<int> G[] , int V){
    bool visited[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    
    for (int i = 0; i < V; i++)
    {
        if(visited[i] == false){
            DFS_visit(G , i , visited);
        }
    }
    
}

int main(){
     int v = 7;

    vector <int> G[v];

    add_Edge(G ,0 ,1);
    add_Edge(G ,0 ,4);
    add_Edge(G ,1 , 2);
    add_Edge(G ,2 ,3);
    add_Edge(G ,4 ,5);
    add_Edge(G ,4 ,6);
    
    print_Graph(G , v);

    DFS(G , 4 );
    return 0;
}