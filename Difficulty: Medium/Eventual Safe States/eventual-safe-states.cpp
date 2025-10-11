class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // Step 1: Build reverse graph and indegree
        vector<int> revAdj[V];
        vector<int> indegree(V, 0);
        
        for(int u = 0; u < V; u++) {
            for(int v : adj[u]) {
                revAdj[v].push_back(u); // reverse edge
                indegree[u]++;          // count outgoing edges of original
            }
        }
        
        // Step 2: Queue for nodes with 0 outgoing edges in original graph
        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        
        // Step 3: Topological BFS
        vector<int> safe;
        while(!q.empty()) {
            int node = q.front(); q.pop();
            safe.push_back(node);
            
            for(int prev : revAdj[node]) {
                indegree[prev]--;
                if(indegree[prev] == 0) q.push(prev);
            }
        }
        
        sort(safe.begin(), safe.end());
        return safe;
    }
};
