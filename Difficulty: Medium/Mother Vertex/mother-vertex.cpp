class Solution {
  public:
    void dfs(int node, vector<int> adj[], vector<int>& vis) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) dfs(it, adj, vis);
        }
    }

    int findMotherVertex(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        int lastFinished = -1;

        // Step 1: Perform DFS for all vertices
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis);
                lastFinished = i; // last vertex whose DFS finishes
            }
        }

        // Step 2: Check if lastFinished can reach all vertices
        fill(vis.begin(), vis.end(), 0);
        dfs(lastFinished, adj, vis);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) return -1; // Not a mother vertex
        }

        return lastFinished;
    }
};
