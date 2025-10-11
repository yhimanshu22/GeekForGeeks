class Solution {
public:
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Step 1: Directions a knight can move
        vector<int> dx = {-2,-1,1,2,2,1,-1,-2};
        vector<int> dy = {1,2,2,1,-1,-2,-2,-1};

        // Step 2: Distance array to track minimum steps
        vector<vector<int>> dist(n+1, vector<int>(n+1, -1));

        // Step 3: BFS queue
        queue<pair<int,int>> q;
        int sx = knightPos[0], sy = knightPos[1];
        int tx = targetPos[0], ty = targetPos[1];

        dist[sx][sy] = 0;
        q.push({sx, sy});

        while(!q.empty()) {
            auto [x, y] = q.front(); q.pop();

            // If target reached
            if(x == tx && y == ty) return dist[x][y];

            for(int k = 0; k < 8; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                // Check valid move
                if(nx >= 1 && ny >= 1 && nx <= n && ny <= n && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return -1; // Target unreachable (should not happen in normal chessboard)
    }
};
