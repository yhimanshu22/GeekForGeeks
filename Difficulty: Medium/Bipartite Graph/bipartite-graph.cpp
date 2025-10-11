class Solution {
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
         // Step 1: Build adjacency list
        vector<int> adj[V];
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // undirected graph
        }
        
         // Step 2: Initialize colors (-1 = uncolored)
        vector<int> color(V, -1);
        
        // Step 3: Check each component
        for (int i = 0; i < V; i++) {
            if (color[i] != -1) continue; // already colored

            queue<int> q;
            q.push(i);
            color[i] = 0; // start coloring with 0

            while (!q.empty()) {
                int node = q.front(); q.pop();
                for (int neigh : adj[node]) {
                    if (color[neigh] == -1) {
                        color[neigh] = 1 - color[node]; // alternate color
                        q.push(neigh);
                    } else if (color[neigh] == color[node]) {
                        return false; // same color on adjacent nodes → not bipartite
                    }
                }
            }
        }
        return true;
        
    }
};