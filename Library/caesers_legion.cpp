#include<bits/stdc++.h>
#define fastIO  (ios::sync_with_stdio(0),cin.tie(0))
#define ll long long int
using namespace std;
ll limit_k1, limit_k2;
ll dp[101][101][11][11];

ll legionDP(ll n1, ll n2, ll k1, ll k2){
    if((n1 + n2) == 0) return 1;

    if(dp[n1][n2][k1][k2] != -1) return dp[n1][n2][k1][k2];

    ll x = 0;
    ll y = 0;

    if(n1>0 && k1>0) x = legionDP(n1 - 1, n2, k1 - 1, limit_k2);
    if(n2>0 && k2>0) y = legionDP(n1, n2 - 1, limit_k1, k2 - 1);

    dp[n1][n2][k1][k2] = (x+y) % 100000000;

    return dp[n1][n2][k1][k2];
}


int main(){
    fastIO;

    ll n1, n2;
    cin>>n1>>n2>>limit_k1>>limit_k2;
    memset(dp, -1, sizeof(dp));
    cout<<legionDP(n1,n2,limit_k1,limit_k2);


    return 0;
}