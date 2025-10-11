// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<pair<int,int>> adj[V];
        
        for(auto& e:edges){
            int u = e[0];
            int v =e[1];
            int w = e[2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        vector<int> dist(V,1e9);
        dist[src] =0;
        
         // Step 3: Min-heap (distance, node)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src});
        
        while(!pq.empty()){
            auto [d,node] = pq.top();pq.pop();
            
            for(auto &[neigh,weight] : adj[node]){
                if(dist[node] + weight < dist[neigh]){
                    dist[neigh] = dist[node] + weight;
                    pq.push({dist[neigh], neigh});
                } 
            }
        }
        
        return dist;
        
    }
};