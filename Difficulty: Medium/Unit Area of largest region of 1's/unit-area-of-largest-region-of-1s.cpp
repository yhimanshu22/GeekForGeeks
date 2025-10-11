class Solution {
  public:
    // Directions: 8 neighbors (up, down, left, right + diagonals)
    int dx[8] = {-1,-1,-1,0,0,1,1,1};
    int dy[8] = {-1,0,1,-1,1,-1,0,1};
    
    int dfs(int x, int y, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        if(x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0)
            return 0;
        
        grid[x][y] = 0; // mark visited
        int area = 1;   // count current cell
        
        for(int k = 0; k < 8; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            area += dfs(nx, ny, grid);
        }
        return area;
    }
    
    int findMaxArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxArea = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(i, j, grid));
                }
            }
        }
        return maxArea;
    }
};
