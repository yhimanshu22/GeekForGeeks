class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int,int> source,
                     pair<int,int> destination) {
        int n = grid.size();
        int m = grid[0].size();
        
        // If source or destination is blocked
        if(grid[source.first][source.second] == 0 || 
           grid[destination.first][destination.second] == 0)
            return -1;
        
        // 4 directions: up, down, left, right
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        queue<pair<int,int>> q;
        
        q.push(source);
        dist[source.first][source.second] = 0;
        
        while(!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            
            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                
                if(nx >= 0 && nx < n && ny >= 0 && ny < m &&
                   grid[nx][ny] == 1 &&
                   dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        
        return (dist[destination.first][destination.second] == 1e9) ? -1 :
                dist[destination.first][destination.second];
    }
};
