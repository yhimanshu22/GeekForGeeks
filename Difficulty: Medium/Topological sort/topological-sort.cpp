class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        vector<int> indegree(V, 0);
        vector<int> topo;

        // Step 1: Build adjacency list and compute indegree
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        // Step 2: Add all nodes with indegree 0
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        // Step 3: Process nodes
        while (!q.empty()) {
            int node = q.front(); q.pop();
            topo.push_back(node);

            for (auto neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        // Step 4: Check if topological ordering is valid
        // If graph has a cycle, topo.size() != V
        return topo;
    }
};
