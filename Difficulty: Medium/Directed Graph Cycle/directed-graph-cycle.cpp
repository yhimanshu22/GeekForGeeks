class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        
        for (auto &it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }
        
        vector<int> vis(V, 0), pathVis(V, 0);
        
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (helper(i, adj, vis, pathVis)) return true;
            }
        }
        return false;
    }
    
    bool helper(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;
        
        for (auto nbr : adj[node]) {
            if (!vis[nbr]) {
                if (helper(nbr, adj, vis, pathVis)) return true;
            }
            else if (pathVis[nbr]) return true;
        }
        
        pathVis[node] = 0; // backtrack
        return false;
    }
};
