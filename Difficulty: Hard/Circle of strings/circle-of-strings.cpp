class Solution {
  public:
    void dfs(int node, vector<int> adj[], vector<int> &vis) {
        vis[node] = 1;
        for(auto &neigh : adj[node]) {
            if(!vis[neigh]) dfs(neigh, adj, vis);
        }
    }

    int isCircle(vector<string> &arr) {
        vector<int> in(26, 0), out(26, 0);
        vector<int> adj[26];
        
        // Step 1: Build the graph
        for(string &s : arr) {
            int u = s.front() - 'a';
            int v = s.back() - 'a';
            adj[u].push_back(v);
            out[u]++;
            in[v]++;
        }

        // Step 2: Check in-degree == out-degree
        for(int i = 0; i < 26; i++) {
            if(in[i] != out[i])
                return 0;
        }

        // Step 3: Find first vertex with outgoing edge
        int start = -1;
        for(int i = 0; i < 26; i++) {
            if(out[i] > 0) {
                start = i;
                break;
            }
        }

        // Step 4: DFS to check connectivity
        vector<int> vis(26, 0);
        dfs(start, adj, vis);

        // Step 5: Ensure all non-zero degree nodes are visited
        for(int i = 0; i < 26; i++) {
            if(out[i] > 0 && !vis[i])
                return 0;
        }

        return 1; // Circle exists
    }
};
