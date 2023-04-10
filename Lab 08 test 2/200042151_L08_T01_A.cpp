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
const int MAXN = 100;
int n, colors[MAXN];
int dp[MAXN][MAXN];

int main() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> colors[i];


    memset(dp, 0, sizeof(dp));
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n-len; i++) {
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + colors[i] * colors[k+1] * colors[j]);
                }
            }
        }

    cout << dp[0][n-1] << endl;
    }
    return 0;
}