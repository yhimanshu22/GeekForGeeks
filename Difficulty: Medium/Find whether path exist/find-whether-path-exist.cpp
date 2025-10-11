
class Solution {
  public:
    // Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        if (n == 0) return false;
        int m = grid[0].size();
        
        int srcX, srcY;
        bool foundSource = false;
        
        for (int i = 0; i < n && !foundSource; i++) {
            for (int j = 0; j < m && !foundSource; j++) {
                if (grid[i][j] == 1) {
                    srcX = i;
                    srcY = j;
                    foundSource = true;
                }
            }
        }
        
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int,int>> q;
        q.push({srcX, srcY});
        visited[srcX][srcY] = 1;
        
         int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

         
           while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();

            if (grid[x][y] == 2) return true; // reached destination

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                    !visited[nx][ny] && (grid[nx][ny] == 2 || grid[nx][ny] == 3)) {
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }

        return false; // no path found

    }
};