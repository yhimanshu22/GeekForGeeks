class Solution {
  public:
    int dfs(int u, vector<vector<int>>& adj, int duration[], 
            vector<int>& dp, vector<int>& state, bool& hasCycle) {
        if (dp[u] != -1) return dp[u];
        if (state[u] == 1) {  // cycle detected
            hasCycle = true;
            return 0;
        }
        if (state[u] == 2) return dp[u];

        state[u] = 1; // mark visiting
        int maxChild = 0;
        for (int v : adj[u]) {
            maxChild = max(maxChild, dfs(v, adj, duration, dp, state, hasCycle));
        }
        state[u] = 2; // mark visited

        return dp[u] = duration[u] + maxChild;
    }

    int minTime(vector<pair<int, int>> &dependency, int duration[], int n, int m) {
        vector<vector<int>> adj(n);
        for (auto &d : dependency) {
            int u = d.first, v = d.second;
            adj[u].push_back(v);
        }

        vector<int> dp(n, -1), state(n, 0);
        bool hasCycle = false;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(i, adj, duration, dp, state, hasCycle));
            if (hasCycle) return -1; // or handle cycle case (project can't finish)
        }

        return ans;
    }
};
