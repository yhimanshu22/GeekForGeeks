// User function Template for C++

class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
           int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        
        vector<vector<int>> visited(n, vector<int>(m, 0));
        set<vector<pair<int,int>>> distinctShapes;
        
         for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    vector<pair<int,int>> shape;
                    dfs(i, j, grid, visited, shape, i, j);
                    distinctShapes.insert(shape);
                }
            }
        }
        return distinctShapes.size();

    }
    
   void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& visited,
             vector<pair<int,int>>& shape, int baseX, int baseY) {
        int n = grid.size();
        int m = grid[0].size();
        visited[x][y] = 1;
        shape.push_back({x - baseX, y - baseY}); // store relative position

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                grid[nx][ny] == 1 && !visited[nx][ny]) {
                dfs(nx, ny, grid, visited, shape, baseX, baseY);
            }
        }
    }
};
