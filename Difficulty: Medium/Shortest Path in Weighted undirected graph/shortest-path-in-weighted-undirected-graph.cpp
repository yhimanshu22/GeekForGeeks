class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list
        vector<pair<int, int>> adj[n + 1];
        for (auto &it : edges) {
            int u = it[0], v = it[1], wt = it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt}); // remove if directed
        }

        // Step 2: Distance and parent arrays
        vector<int> dist(n + 1, 1e9), parent(n + 1);
        for (int i = 1; i <= n; i++) parent[i] = i;

        // Step 3: Min heap (priority queue)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[1] = 0;
        pq.push({0, 1});

        // Step 4: Dijkstra’s algorithm
        while (!pq.empty()) {
            auto it = pq.top(); pq.pop();
            int node = it.second;
            int dis = it.first;

            for (auto &nbr : adj[node]) {
                int adjNode = nbr.first;
                int wt = nbr.second;

                if (dis + wt < dist[adjNode]) {
                    dist[adjNode] = dis + wt;
                    pq.push({dist[adjNode], adjNode});
                    parent[adjNode] = node;
                }
            }
        }

        // Step 5: If unreachable
        if (dist[n] == 1e9) return {-1};

        // Step 6: Reconstruct path
        vector<int> path;
        int node = n;
        while (parent[node] != node) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());

        // Append total distance at front
        path.insert(path.begin(), dist[n]);
        return path;
    }
};
