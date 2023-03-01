#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9;

vector<pair<int, int>> adj[100001];
int dist[100001];

void dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, s));
    dist[s] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int st_weight=pq.top().first;
        pq.pop();
        if(dist[u]<st_weight)continue;
        for (auto v : adj[u]) {
            int w = v.second;
            int weight = v.first;

            if (st_weight + weight < dist[w]) {
                dist[w] = st_weight + weight;
                pq.push(make_pair(dist[w], w));
            }
        }
    }
}

void clear(int m){
    for(int i=0;i<=m;i++){
        adj[i].clear();
    }
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin >> n >> m;
        fill_n(dist, n + 1, INF);
        // memset(dist, 0x3f, sizeof(dist));
        for (int i = 1; i <= m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back(make_pair(w, v));
            adj[v].push_back(make_pair(w, u));
        }

        int s,d;
        cin >> s >> d;
        dijkstra(s);

        if(dist[d] == INF){
            cout<<"NO"<<endl;
        }
        else{
            cout<<dist[d]<<endl;
        }
        clear(m);
        // for (int i = 1; i <= n; i++) {
        //     if (dist[i] == INF) {
        //         cout << "NO";
        //     } else {
        //         cout << dist[i] << endl;
        //     }
        // }
    }
    

    return 0;
}
