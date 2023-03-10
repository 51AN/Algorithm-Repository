#include<bits/stdc++.h>
using namespace std;
long long graph[100][100];


void  floydWarshal(int node)
{
    int k,i,j;
    for(k=1;k<=node;k++){
        for(i=1;i<=node;i++){
            for(j=1;j<=node;j++){
                graph[i][j]=min(graph[i][j], graph[i][k]+graph[k][j]);
            }
        }
    }
}

void findDistance(int n, int *distance){
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(graph[i][j] == INT_MAX)
            {
                distance[i] = -1;
                break;
            }
            else{
                distance[i] += graph[i][j];
            }
        }
        
    }
}

int main()
{
    int i,j,m,n,u,v,w;
    int distance[100] = {-1};

    for(i=0;i<100;i++){
        for(j=0;j<100;j++){
            if(i==j){
                graph[i][j]=0;
            }
            else{
                graph[i][j]=INT_MAX;
            }
        }
    }

    cin>>n>>m;

    while(m--){
        cin>>u>>v>>w;
        graph[u][v]=w;
        graph[v][u]=w;//make bi-directional
    }



    floydWarshal(n);
    findDistance(n, distance);
    
    int min = INT_MAX;
    for(int i = 1 ; i<=n ; i++){
        if(min>distance[i])
            min = distance[i];//find out minimum distance
    }

    for(int i = 1 ; i<=n ; i++){
        if(distance[i] == min ){
            cout<<i<< " ";//print indexes with minimum distance
        }
        // cout<<distance[i] <<" ";
    }


    


}
