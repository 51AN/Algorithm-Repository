#include<bits/stdc++.h>
#define ll                                               long long int
#define fastIO  (ios::sync_with_stdio(0),cin.tie(0));
#define re                        return 0;
#define nl                                                "\n"
#define f(i,n)                                           for(int i = 0 ; i < n ; i ++)
#define f1(i,n)                                          for(int i = 1 ; i <= n ; i ++)
#define fb(i,n)                                          for(int i = n - 1 ; i => 0 ; i --)
#define v(i)                                             vector<int>v[i];
#define sortv(a)                                         sort(a.begin(),a.end())
#define test(t)                                          ll t; cin>>t; while(t--)
#define YES                                              cout<<"YES"<<endl
#define NO                                               cout<<"NO"<<endl


using namespace std;


void dfs(int node,vector<int> &visited,vector<int> adjList[]){
              visited[node]=1;
              
            for(auto it : adjList[node]){
                if(visited[it]!=1){
                    visited[it]=1;
                    visited.push_back(it);
                    dfs(it,visited,adjList);
                }
            }
    }

int main(){

    fastIO;
    int n;
    cin>>n;
    int a[n][n];

    f(i,n){
        f(j,n){
            cin>>a[i][j];
        }
    }

    vector<int> adjList[n];

    f(i,n){
        f(j,n){
            if((a[i][j] == 1) && (i != j)){
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
            
        }
    }

    vector<int>visited(n,0);
    int province = 0;

    f(i,n){
        if(visited[i] != 1){
            province++;
            dfs(i,visited,adjList);
        }
    }

    cout<<province<<nl;




    re;

}