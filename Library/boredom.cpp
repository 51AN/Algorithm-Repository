#include<bits/stdc++.h>
#define fastIO  (ios::sync_with_stdio(0),cin.tie(0))
#define ll long long int
using namespace std;

ll cnt[100005] = {0};
ll dp[100005];

ll boredDP(ll m){
    if(m == 0) return 0;
    if(m == 1) return dp[m];
    if(dp[m] != -1) return dp[m];

    dp[m] = max(boredDP(m-1), boredDP(m-2) + cnt[m] * m);
    return dp[m];
}

int main(){

    fastIO;

    ll n, x, mx = 0;

    cin>>n;

    for(int i = 0 ; i < n ; i++){
        cin>>x;
        cnt[x]++;

        mx = max(mx, x);
    }

    memset(dp, -1, sizeof(dp));

    dp[0] = 0;
    dp[1] = cnt[1];

    cout<<boredDP(mx)<<endl;

    return 0;
}