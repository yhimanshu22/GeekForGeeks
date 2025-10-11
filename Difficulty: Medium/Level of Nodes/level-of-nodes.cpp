class Solution {
  public:
    int nodeLevel(int V, vector<int> adj[], int X) {
        vector<int> level(V, -1);  // store level of each node
        queue<int> q;
        
        int root = 0; // assuming root node is 0
        level[root] = 0;
        q.push(root);
        
        while(!q.empty()) {
            int node = q.front(); q.pop();
            
            for(int neighbor : adj[node]) {
                if(level[neighbor] == -1) { // unvisited
                    level[neighbor] = level[node] + 1;
                    q.push(neighbor);
                }
            }
        }
        
        return level[X]; // returns -1 if node X is unreachable
    }
};
