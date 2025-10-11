class Solution {
public:
    int minimumCostPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Directions: up, down, left, right
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        // Distance array
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = grid[0][0];

        // Min-heap: {cost, {x, y}}
        priority_queue< pair<int, pair<int,int>>, 
                        vector<pair<int,pair<int,int>>>, 
                        greater<>> pq;
        pq.push({dist[0][0], {0, 0}});

        while(!pq.empty()) {
            auto [cost, pos] = pq.top(); pq.pop();
            int x = pos.first, y = pos.second;

            if(x == n-1 && y == m-1) return cost; // reached target

            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                // Check valid cell
                if(nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    int newCost = cost + grid[nx][ny];
                    if(newCost < dist[nx][ny]) {
                        dist[nx][ny] = newCost;
                        pq.push({newCost, {nx, ny}});
                    }
                }
            }
        }

        return dist[n-1][m-1];
    }
};
