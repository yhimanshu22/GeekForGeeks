class Solution {
  public:
    void dfs(int node, vector<int> adj[], vector<bool> &visited) {
        visited[node] = true;
        for(auto neigh : adj[node]) {
            if(!visited[neigh])
                dfs(neigh, adj, visited);
        }
    }

    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Step 1: Build adjacency list
        vector<int> adj[V];
        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // Step 2: Remove edge (c,d)
        adj[c].erase(remove(adj[c].begin(), adj[c].end(), d), adj[c].end());
        adj[d].erase(remove(adj[d].begin(), adj[d].end(), c), adj[d].end());

        // Step 3: DFS from c
        vector<bool> visited(V, false);
        dfs(c, adj, visited);

        // Step 4: Check if d is reachable
        return !visited[d]; // if d is not visited → bridge
    }
};
