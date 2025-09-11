// User function Template for C++

class Solution {
  public:
    int dfs(int u, vector<vector<int>>& adj, vector<int>& dp) {
        if (dp[u] != -1) return dp[u];

        int maxChild = 0;
        for (int v : adj[u]) {
            maxChild = max(maxChild, dfs(v, adj, dp));
        }

        return dp[u] = 1 + maxChild;  // color of u
    }

    int minColour(int N, int M, vector<int> mat[]) {
        vector<vector<int>> adj(N + 1);

        // Build adjacency list
        for (int i = 0; i < M; i++) {
            int u = mat[i][0];
            int v = mat[i][1];
            adj[u].push_back(v);
        }

        vector<int> dp(N + 1, -1);
        int ans = 0;

        // Run DFS for all nodes
        for (int i = 1; i <= N; i++) {
            ans = max(ans, dfs(i, adj, dp));
        }

        return ans;
    }
};
