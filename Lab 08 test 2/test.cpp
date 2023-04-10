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

ll dp[105][105];
ll arr[105];

ll sum(int i,int j)
{
    long long res=0;
    for(int k=i; k<=j;k++)
    {
        res+=arr[k];
        res%=100;
    }
    return res;
}

ll minSmoke(int i, int j)
{
    if(i>=j) 
        return 0;
    if(dp[i][j]!=-1) 
        return dp[i][j];

    dp[i][j]=INF;

    for(int k=i; k<=j;k++)
    {
        ll temp = minSmoke(i,k) + minSmoke(k+1,j);
        temp += sum(i,k)*sum(k+1,j); 
        dp[i][j]=min(dp[i][j],temp);
    }
    return dp[i][j];
}

int main()
{
    fastIO;
    int n;
    cin >> n;
    memset(dp,-1,sizeof(dp));
    f(i,n){
        cin>>arr[i];
    }
    cout<<minSmoke(0,n-1)<<endl;



    re;

}