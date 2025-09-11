class Solution {
  public:
    int bfs(int src, int N, vector<vector<int>>& adj) {
        vector<int> dist(N+1, -1);
        queue<int> q;
        
        dist[src] = 0;
        q.push(src);
        
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        
        int maxDist = 0;
        for (int i = 1; i <= N; i++) {
            maxDist = max(maxDist, dist[i]);
        }
        return maxDist;
    }
    
    int partyHouse(int N, vector<vector<int>> &adj) {
        int ans = INT_MAX;
        for (int i = 1; i <= N; i++) {
            ans = min(ans, bfs(i, N, adj));
        }
        return ans;
    }
};
