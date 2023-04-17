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
ll mod = 1e9+7;
ll mask = 0;
const int MAXN = 16;
int n, mat[MAXN][MAXN];
int dp[1<<16][16];

bool isOn(int N,int pos)
{
    return (bool)(N & (1<<pos)) ;
}
int turnOn(int N,int pos)
{
    return (N | (1<<pos));
}

int compatibleWays(int mask, int k){
    if(mask == (1<<n)-1) 
        return 1;
    if(dp[mask][k] != -1)
        return dp[mask][k];
    int total = 0;
    for(int i=0; i<n; i++)
    {
        if(!isOn(mask, i) && mat[k][i] != 0)
        {
            total += (compatibleWays(turnOn(mask, i), k+1))%(mod);
        }
    }
    dp[mask][k] = total;
    return dp[mask][k];
    
}

int main()
{
    fastIO;
    cin>>n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
                cin >> mat[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout<<compatibleWays(mask, 0);

    re;

}