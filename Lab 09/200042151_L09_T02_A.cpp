#include<bits/stdc++.h>
using namespace std;
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
#define INF 0x3F3F3F3F
#define INT_MAX 2147483647
const int MAX = 205;

const int maxnodes = 100;
int n,pr[110],cap[110][110];
int reg[101] = {0};
int arr[101] = {0};


int bfs(int src,int des)
{
    int vis[110]= {0};
    vis[src]=1;
    pr[src]=-1;
    queue<int>Q;
    Q.push(src);

    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(int i=1; i<=n; i++)
        {
            if(vis[i] or cap[u][i]<=0) continue;
            Q.push(i);
            vis[i]=1;
            pr[i]=u;

        }
    }

    return vis[des];
}
int maxFlow(int src,int des)
{
    int f=0;
    while(bfs(src,des))
    {

        int path=1e9;
        for(int i=des; i!=src; i=pr[i]) path=min(path,cap[pr[i]][i]);

        for(int i=des; i!=src; i=pr[i])
        {

            int u=pr[i];
            int v=i;

            cap[u][v]-=path;
            cap[v][u]+=path;

        }

        f+=path;

    }
    return f;
}



int main()
{
    fastIO;
    int test,cs=0;
    cin>>test;
    while(test--)
    {
        memset(cap,0,sizeof(cap));


        int m,s,t;
        cin>>n;
        f(i,n){
            cin>>reg[i];
        }

        cin>>m;

        for(int i=0;i<m;i++)
        {
            int a,b,c;
            cin >> a >> b >> c;
            cap[a][b]+=c;
            cap[b][a]+=c;
        }
        int b,d;
        cin>>b>>d;
        f(i,b+d){
            cin>>arr[i];
        }
        cout <<"Case "<<++cs<<": "<< maxFlow(0,9) << "\n";

    }
    re;

}