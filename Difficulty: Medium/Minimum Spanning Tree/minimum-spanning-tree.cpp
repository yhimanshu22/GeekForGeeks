class Solution {
public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list {neighbor, weight}
        vector<pair<int,int>> adj[V];
        for(auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); // undirected graph
        }

        // Step 2: Initialize arrays
        vector<int> key(V, 1e9); // minimum weight edge to include in MST
        vector<bool> inMST(V, false); // track nodes included in MST
        key[0] = 0; // start from vertex 0
        int totalWeight = 0;

        // Step 3: Use priority queue (min-heap) to pick min weight edge
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0, 0}); // {weight, node}

        while(!pq.empty()) {
            auto [w, u] = pq.top(); pq.pop();
            if(inMST[u]) continue; // already included
            inMST[u] = true;
            totalWeight += w;

            for(auto &[v, weight] : adj[u]) {
                if(!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    pq.push({weight, v});
                }
            }
        }

        return totalWeight;
    }
};

