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

int main(){

    fastIO;
    int n;
    cin>>n;
    int a[n][n];
    bool isceleb = true;
    int celeb = -1;
    f(i,n){
        f(j,n){
            cin>>a[i][j];
        }
    }

    f(i,n){
        f(j,n){
            if((a[i][j] == 1) && (i != j)){
                isceleb = false;
            }
        }
        if(isceleb){
            celeb = i;
            break;
        }else{
            isceleb = true;
        }
    }

    
    if(celeb != -1)
        cout<<"Person "<<celeb<<" is the celebrity"<<nl;
    else{
        cout<<"There is no celebrity"<<nl;
    }


    re;

}