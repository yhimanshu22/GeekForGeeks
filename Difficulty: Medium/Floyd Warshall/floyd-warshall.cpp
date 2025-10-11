class Solution {
public:
    void floydWarshall(vector<vector<int>> &dist) {
        int V = dist.size();

        // Step 1: Floyd-Warshall main loop
        for (int k = 0; k < V; k++) {           // intermediate vertex
            for (int i = 0; i < V; i++) {       // source vertex
                for (int j = 0; j < V; j++) {   // destination vertex
                    if (dist[i][k] != 1e8 && dist[k][j] != 1e8) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
    }
};
