int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited){
    int n = grid.size();
    int m = grid[0].size();

    if(i>=n || j>=m || i<0 || j<0 || grid[i][j] == 0) return 1;
    if(grid[i][j]==-1) return 0;
    
    grid[i][j]=-1;

    return dfs(grid, i+1, j, visited) + dfs(grid, i-1, j, visited)+ dfs(grid, i, j+1, visited) + dfs(grid, i, j-1, visited);

}

int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m, false));
        int parameter = 0;

        f(i,n){
            f(j,m){
                if(grid[i][j] == 1){
                    parameter = dfs(grid, i , j, visited);
                }
            }
        }

        return parameter;
    }