class Solution {
  public:
  
    void dfs(int x,int y,vector<vector<char>>& grid,vector<vector<int>>& vis){
        int n = grid.size();
        int m =grid[0].size();
        
        vis[x][y] = 1;
        
        int dx[8] = {-1, -1, -1,  0, 0, 1, 1, 1};
        int dy[8] = {-1,  0,  1, -1, 1, -1, 0, 1};
   
        for(int i=0;i<8;i++){
            int nx = x+dx[i];
            int ny = y+ dy[i];
            
            if(nx >= 0 && ny < m && nx < n && ny >=0 && grid[nx][ny] =='L'
            && !vis[nx][ny]){
                dfs(nx,ny,grid,vis);
            }
        }
    }
    
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 'L' && !vis[i][j]){
                    cnt++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        
        return cnt;
    }
};