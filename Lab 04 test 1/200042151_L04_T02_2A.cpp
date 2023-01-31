#include <bits/stdc++.h>
using namespace std;
 
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
 

bool bicolorable(vector<int> adj[], int v, vector<bool>& visited, vector<int>& color)
{
 
    for (auto u : adj[v]) {

        if (visited[u] == false) {

            visited[u] = true;//mark as visited
            color[u] = !color[v];//assign opposite color
 
            if (!bicolorable(adj, u, visited, color)) return false;//subtree not bipartite graph
        }

        else if (color[u] == color[v]) return false; //colors of adjacent nodes are same
    }
    return true;
}
 
int main()
{

    int N,M;
    cin>>N>>M;

    vector<int> adj[N];
    vector<bool> visited(N,false);
    vector<int> color(N);

    int a,b;
    for(int i = 0 ; i < M ; i++){
        cin>>a>>b;
        addEdge(adj,a,b);
    }
    
    //marking first node as true and colored
    visited[0] = true;
    color[0] = 0;
 
    if (bicolorable(adj, 0, visited, color)) {
        cout << "BICOLORABLE";
    }
    else {
        cout << "NOT BICOLORABLE";
    }
 
    return 0;
}