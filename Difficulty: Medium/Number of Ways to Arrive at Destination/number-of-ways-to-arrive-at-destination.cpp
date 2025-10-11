class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        
        // Step 1: Build adjacency list {neighbor, weight}
        vector<pair<int,int>> adj[n];
        for(auto &r : roads) {
            int u = r[0], v = r[1], w = r[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w}); // undirected
        }
        
        // Step 2: Dijkstra initialization
        vector<long long> dist(n, 1e18);
        vector<long long> ways(n, 0);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0}); // {distance, node}
        
        // Step 3: Dijkstra
        while(!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if(d > dist[u]) continue; // skip outdated
            
            for(auto &[v,w] : adj[u]) {
                if(dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    ways[v] = ways[u];  // new shortest path
                    pq.push({dist[v], v});
                } else if(dist[v] == dist[u] + w) {
                    ways[v] = (ways[v] + ways[u]) % MOD; // another shortest path
                }
            }
        }
        
        return ways[n-1] % MOD;
    }
};
