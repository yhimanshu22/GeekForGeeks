class Solution {
  public:
    int isNegativeWeightCycle(int n, vector<vector<int>> edges) {
        const int INF = 1e9;
        vector<int> dist(n, 0); // Initialize distances to 0 for cycle detection
        
        // Step 1: Relax all edges n-1 times
        for(int i = 0; i < n - 1; i++) {
            for(auto &e : edges) {
                int u = e[0], v = e[1], w = e[2];
                if(dist[u] + w < dist[v])
                    dist[v] = dist[u] + w;
            }
        }
        
        // Step 2: Check for negative weight cycles
        for(auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if(dist[u] + w < dist[v])
                return 1; // Negative weight cycle exists
        }
        
        return 0; // No negative weight cycle
    }
};
