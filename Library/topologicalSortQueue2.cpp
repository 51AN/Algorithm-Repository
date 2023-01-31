#include<bits/stdc++.h>
#define ll                                               long long int
#define fastIO  (ios::sync_with_stdio(0),cin.tie(0));
#define re                        return 0;
#define nl                                                "\n"
#define f(i,n)                                           for(int i = 0 ; i < n ; i ++)
#define f1(i,n)                                          for(int i = 1 ; i <= n ; i ++)
#define fb(i,n)                                          for(int i = n - 1 ; i >= 0 ; i --)
#define v(i)                                             vector<int>v[i];
#define sortv(a)                                         sort(a.begin(),a.end())
#define test(t)                                          ll t; cin>>t; while(t--)
#define YES                                              cout<<"YES"<<endl
#define NO                                               cout<<"NO"<<endl

using namespace std;

vector<vector<int>> graph(10); // Adjacency list representation of the graph
vector<int> sorted; // Resulting topologically sorted order
 
void topological_sort(int n) {
    queue<int> q;
    //find inorder
    vector<int> indegree(n,0); // Indegree of each node
    f(i,n){
        f(j,graph[i].size()){
            int neighbor = graph[i][j];
            indegree[neighbor]++;
        }
    }
    // Enqueue all nodes with indegree 0
    f(i,indegree.size()) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        sorted.push_back(current);

        // Decrement indegree of neighbors
        f(i,graph[current].size()){
            int neighbor = graph[current][i];
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
}

int main() {

    // graph = {{1,0},{2,0},{3,1},{3,2}} ;
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(3);

    topological_sort(4);

    // Print the sorted order
    for (int i = 0; i < sorted.size(); i++) {
        cout << sorted[i] << " ";
    }

    return 0;
}
