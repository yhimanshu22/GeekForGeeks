class Solution {
public:
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int V = adj.size();
        vector<int> dist(V, -1); // Distance to each node (-1 if unreachable)
        queue<int> q;

        dist[src] = 0;
        q.push(src);

        while(!q.empty()) {
            int u = q.front(); q.pop();

            for(int v : adj[u]) {
                if(dist[v] == -1) { // Not visited yet
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        return dist;
    }
};
