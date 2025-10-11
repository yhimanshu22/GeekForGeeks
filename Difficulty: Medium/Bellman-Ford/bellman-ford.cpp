class Solution {
public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Step 1: Initialize distances
        vector<int> dist(V, 1e8);
        dist[src] = 0;

        // Step 2: Relax all edges V-1 times
        for(int i = 0; i < V - 1; i++) {
            for(auto &e : edges) {
                int u = e[0], v = e[1], w = e[2];
                if(dist[u] != 1e8 && dist[u] + w < dist[v])
                    dist[v] = dist[u] + w;
            }
        }
        

        // Step 3: Check for negative weight cycles
        for(auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if(dist[u] != 1e8 && dist[u] + w < dist[v])
                return {-1}; // Negative cycle detected
        }

        return dist;
    }
};
