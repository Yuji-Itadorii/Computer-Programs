#include<bits/stdc++.h>
using namespace std;

void add_Edge( vector <int> G[] , int u , int v){
    G[u].push_back(v);
    G[v].push_back(u);
}

void print_Graph( vector <int> G[] , int v){
    for (int i = 0; i < v; i++)
    {
        cout<<i<<"->";
        for(int x : G[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}

vector <int> shortDistance( vector <int> G[] , int V , int s){
    vector <bool> visited(V+1 , false);
    vector <int> distance(V , -1);
    queue <int> q;
    visited[s] = true;
    distance[s] = 0;
    q.push(s);
    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();
        for (int v : G[u])
        {
            if(visited[v] == false){

                visited[v] = true;
                distance[v] = distance[u] +1;
                q.push(v);
            }
        }
        
    }

    return distance;
    
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
    
    // print_Graph(G , v);

    vector<int> res = shortDistance(G , v , 0);

    for (int i = 0; i < res.size(); i++)
    {
        cout<<res[i]<<" ";
    }
    

    return 0;
}