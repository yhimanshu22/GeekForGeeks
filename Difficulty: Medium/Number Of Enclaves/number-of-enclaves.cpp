// User function Template for C++

class Solution {
  public:
    void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& visited) {
        int n = grid.size();
        int m = grid[0].size();
        visited[x][y] = 1;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                grid[nx][ny] == 1 && !visited[nx][ny]) {
                dfs(nx, ny, grid, visited);
            }
        }
    }
    
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

          for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1 && !visited[i][0]) dfs(i, 0, grid, visited);
            if (grid[i][m-1] == 1 && !visited[i][m-1]) dfs(i, m-1, grid, visited);
        }
        
         for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1 && !visited[0][j]) dfs(0, j, grid, visited);
            if (grid[n-1][j] == 1 && !visited[n-1][j]) dfs(n-1, j, grid, visited);
        }
        
          int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) count++;
            }
        }

        return count;
        
    }
};
