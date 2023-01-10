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


void dfs(vector<vector<int> >& grid, vector<vector<bool> >& visited, int x, int y,int n, int m, bool &hasCornerCell){

    if (x < 0 || y < 0 || x >= n || y >= m || visited[x][y] == true || grid[x][y] == 1)
        return;
    visited[x][y] = true;
    if(x == 0 || y == 0 || x == n-1 || y == m-1)
    {
      if(grid[x][y] == 0)
        hasCornerCell = true;
    }
    //traversing adjacent nodes :
    dfs(grid, visited, x + 1, y, n, m, hasCornerCell);
    dfs(grid, visited, x, y + 1, n, m, hasCornerCell);
    dfs(grid, visited, x - 1, y, n, m, hasCornerCell);
    dfs(grid, visited, x, y - 1, n, m, hasCornerCell);
}
int countClosedIsland(vector<vector<int> >& grid, int n, int m){

    vector<vector<bool>> visited(n,vector<bool>(m, false));

    int islands = 0; 

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
 
            if ((i != 0 && j != 0 && i != n - 1 && j != m - 1) and (grid[i][j] == 0) and (visited[i][j] == false))
            {

                  bool hasCornerCell = false;
                   
  
                dfs(grid, visited, i, j, n, m, hasCornerCell);

                  if(!hasCornerCell)
                  islands = islands + 1;
            }
        }
    }
 

    return islands;
}
 


int main(){

    fastIO;
    
    vector<vector<int>> grid ={{1,1,1,1,1,1,1,0},{1,0,0,0,0,1,1,0},{1,0,1,0,1,1,1,0},{1,0,0,0,0,1,0,1},{1,1,1,1,1,1,1,0}};

    int n = grid.size();
    int m = grid[0].size();

    cout << countClosedIsland(grid, n, m);



    re;

}