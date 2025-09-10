class Solution {
  public:
    void dfs(int x, int y, vector<vector<char>>& grid, vector<vector<int>>& visited, int dx[], int dy[]) {
        int n = grid.size();
        int m = grid[0].size();
        
        visited[x][y] = 1;
        
        for (int k = 0; k < 8; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            
            if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                !visited[nx][ny] && grid[nx][ny] == 'L') {
                dfs(nx, ny, grid, visited, dx, dy);
            }
        }
    }
    
    int countIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        // 8 directions
        int dx[8] = {-1, -1, -1,  0, 0, 1, 1, 1};
        int dy[8] = {-1,  0,  1, -1, 1,-1, 0, 1};

        int count = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == 'L') {
                    dfs(i, j, grid, visited, dx, dy);
                    count++;
                }
            }
        }
        return count;
    }
};
