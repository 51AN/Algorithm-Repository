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
int n;
int mixtures[100];
int color[100][100];
int dp[100][100];

int smokeAmount(int i, int j)
{
    if(i==j) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    dp[i][j] = INT_MAX;
    for(int k=i; k<j; k++)
    {
        dp[i][j] = min(dp[i][j], smokeAmount(i, k) + smokeAmount(k+1,j) + color[i][k]*color[k+1][j]);
    }

    return dp[i][j];
}

int main()
{
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>mixtures[i];
    }

    memset(dp, -1, sizeof(dp));
    for(int i=0; i<n; i++)
        color[i][i] = mixtures[i];

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            color[i][j] = (mixtures[i] + mixtures[j])%100;
            color[j][i] = color[i][j];
        }
    }

    cout<<smokeAmount(0, n-1)<<endl;
    return 0;
}