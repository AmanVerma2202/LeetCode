class Solution {
    void dfs(vector<vector<int>>& grid,vector<vector<bool>>&vis,int n,int m,int i,int j){
        if(i<0 || i>=n || j<0 || j>=m ) return;
        if(grid[i][j]==1 || vis[i][j]) return ;
        vis[i][j]=true;
        dfs(grid,vis,n,m,i+1,j);
        dfs(grid,vis,n,m,i,j+1);
        dfs(grid,vis,n,m,i-1,j);
        dfs(grid,vis,n,m,i,j-1);
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int res=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,(vector<bool>(m,false)));
        // Mark boundary islands as visited
        for (int i = 0; i < n; ++i) {
            if (grid[i][0] == 0 && !vis[i][0]) dfs(grid, vis, n, m, i, 0);
            if (grid[i][m - 1] == 0 && !vis[i][m - 1]) dfs(grid, vis, n, m, i, m - 1);
        }
        for (int j = 0; j < m; ++j) {
            if (grid[0][j] == 0 && !vis[0][j]) dfs(grid, vis, n, m, 0, j);
            if (grid[n - 1][j] == 0 && !vis[n - 1][j]) dfs(grid, vis, n, m, n - 1, j);
        }
        for ( int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 && !vis[i][j]){
                    dfs(grid,vis,n,m,i,j);
                    res++;
                }
            }
        }
        return res;
    }
};