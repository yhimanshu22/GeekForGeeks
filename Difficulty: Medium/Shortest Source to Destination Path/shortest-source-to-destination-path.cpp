// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
      if (A[0][0] == 0) return -1; // start blocked
        if (0 == X && 0 == Y) return 0; // already at target
        
         vector<vector<int>> dist(N, vector<int>(M, -1));
        queue<pair<int,int>> q;
        
         int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        
        q.push({0,0});
        dist[0][0] = 0;
        
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                
                if (nx >= 0 && ny >= 0 && nx < N && ny < M && A[nx][ny] == 1 && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    if (nx == X && ny == Y) return dist[nx][ny];
                    q.push({nx, ny});
                }
            }
        }
        
        return -1; // unreachable
        
    }
};