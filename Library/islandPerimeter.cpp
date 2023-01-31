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
int vis[101][101];
int dfs(vector<vector<int>>& grid, int i, int j){
    int n = grid.size();
    int m = grid[0].size();

    if(i>=n || j>=m || i<0 || j<0 || grid[i][j] == 0) return 1;
    // if(grid[i][j]==-1) return 0;
    
    // grid[i][j]=-1;
    if(vis[i][j] == 1) return 0;
    vis[i][j] = 1;

    return dfs(grid, i+1, j) + dfs(grid, i-1, j)+ dfs(grid, i, j+1) + dfs(grid, i, j-1);

}

int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int parameter = 0;

        f(i,n){
            f(j,m){
                if(grid[i][j] == 1){
                    parameter = dfs(grid, i , j);
                }
            }
        }

        return parameter;
    }

int main(){

    fastIO;
    vector<vector<int>> grid = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    cout<<islandPerimeter(grid);
    re;

}