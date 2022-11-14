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


void DFS_rec(vector <int> adj[] , int s , stack <int> &st , bool visited[]){
    visited[s] = true;
    for(int u : adj[s]){
        if(visited[u] == false){
            DFS_rec(adj , u , st , visited);
        }
    }

    st.push(s);
}



void topological_DFS(vector<int> adj[] , int V){
    bool visited [V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        if(visited[i] == false){
            DFS_rec(adj, i , st , visited);
        }
    }
    
    while (st.empty() == false) {
        cout << st.top() << " ";
        st.pop();
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

    topological_DFS(adj , V);
    
    return 0;
}