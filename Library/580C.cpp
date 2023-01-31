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


void bfs(int x,int y)
{

    return ;
}


int main(){

    fastIO;
    ll n,m;
    cin>>n>>m;
    int cats[n+1];
    f1(i,n){
        cin>>cats[i];
    }

    vector<vector<int>>adjList;
    f1(i,n-1){
        int index, child;
        cin>>index>>child;
        adjList[index].push_back(child);
    }
    
    queue<int>queue;
    queue.push(1);
    int count = 0;
    int sum[99999] = {0};
    while(!queue.empty()){
        int curr = queue.front();
        queue.pop();

        if(cats[curr])
            sum[curr] += 1;
            
        f(i,adjList[curr].size()){
            queue.push(adjList[curr][i]);
        }

    }

    re;

}