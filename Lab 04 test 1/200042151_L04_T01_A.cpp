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
                // graph[j][i]=min(graph[i][j], graph[i][k]+graph[k][j]);
            }
        }
    }
}

void print(int n)
{
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}

void findDistance(int n, int *distance){
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(graph[i][j] == INT_MAX)
            {
                distance[i] = 0;
                break;
            }
            else{
                distance[i] += graph[i][j];
            }
        }
        
    }

    // for(i=1;i<=n;i++){
    //     for(j=1;j<=n;j++){
    //        if(graph[j][i] == INT_MAX){
    //            distance[j] = 0;
    //            break;
    //        }
    //        else{
    //            distance[j] += graph[j][i];
    //        }
    //     }
      
    // }
}

int main()
{
    int i,j,m,n,u,v,w;
    int distance[100] = {0};

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
        graph[v][u]=w;
    }



    floydWarshal(n);
    findDistance(n, distance);
    print(n);

    for(int i = 0 ; i<n ; i++){
        if(distance[i] != 0){
            cout<<i<< " ";
        }
    }


}
