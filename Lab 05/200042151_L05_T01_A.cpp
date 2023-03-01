#include<bits/stdc++.h>
using namespace std;
long long dp[300][300];
long long LCS(int coin[], int n, int m){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }

    if(m<0){
        return 0;
    }
    if(dp[n][m] != -1){
        return dp[n][m];
    }

    dp[n][m] = LCS(coin, n, m-1) + LCS(coin, n - coin[m],m);
    
    return dp[n][m];

}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n, m;
    cin>>n>>m;
    int coin[m];
    for(int i = 0 ; i<m ; i++){
        cin>>coin[i];
    }

    cout<<LCS(coin,n,m - 1 );
}