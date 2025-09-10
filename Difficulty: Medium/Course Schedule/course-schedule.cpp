class Solution {
  public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& order) {
        visited[node] = 1; // visiting
        for (int neigh : adj[node]) {
            if (visited[neigh] == 1) return false; // cycle detected
            if (visited[neigh] == 0) {
                if (!dfs(neigh, adj, visited, order)) return false;
            }
        }
        visited[node] = 2; // visited
        order.push_back(node);
        return true;
    }

    vector<int> findOrder(int n, vector<vector<int>> prerequisites) {
        vector<vector<int>> adj(n);
        for (auto &pre : prerequisites) {
            int u = pre[1], v = pre[0]; // b -> a
            adj[u].push_back(v);
        }

        vector<int> visited(n, 0);
        vector<int> order;

        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                if (!dfs(i, adj, visited, order)) return {}; // cycle detected
            }
        }

        reverse(order.begin(), order.end()); // stack → correct order
        return order;
    }
};

