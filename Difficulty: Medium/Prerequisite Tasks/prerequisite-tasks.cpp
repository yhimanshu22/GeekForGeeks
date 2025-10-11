class Solution {
  public:
    bool isPossible(int N, int P, vector<pair<int, int>> &prerequisites) {
        // Step 1: Build adjacency list and indegree array
        vector<vector<int>> adj(N);
        vector<int> indegree(N, 0);
        
        for (auto &p : prerequisites) {
            int u = p.second; // prerequisite course
            int v = p.first;  // dependent course
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        // Step 2: Queue for courses with 0 indegree
        queue<int> q;
        for (int i = 0; i < N; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        
        int count = 0; // Number of courses we can take
        
        // Step 3: BFS (Kahn's Algorithm)
        while (!q.empty()) {
            int node = q.front(); q.pop();
            count++;
            for (auto neigh : adj[node]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0) q.push(neigh);
            }
        }
        
        // Step 4: If count == N, all courses can be completed
        return count == N;
    }
};
