class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        // Step 1: Initialize distance matrix
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        for(int i = 0; i < n; i++) dist[i][i] = 0;
        
        // Step 2: Fill direct edges
        for(auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            dist[u][v] = w;
            dist[v][u] = w; // undirected
        }
        
        // Step 3: Floyd-Warshall to find all-pairs shortest distances
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
        
        // Step 4: Count reachable cities within threshold for each city
        int minCount = n, city = 0;
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(i != j && dist[i][j] <= distanceThreshold) count++;
            }
            // Pick the city with smallest count; if tie, largest index
            if(count <= minCount) {
                minCount = count;
                city = i;
            }
        }
        
        return city;
    }
};
