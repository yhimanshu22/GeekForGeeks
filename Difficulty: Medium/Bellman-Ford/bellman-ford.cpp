// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dist(V,1e8);
        
        //iterate over V-1 times
        dist[src] =0;
        for(int i=0;i<V-1;i++){
            
            bool updated = false;
            
            for(auto& e:edges){
                int u = e[0];
                int v = e[1];
                int w= e[2];
                
                if(dist[u] != 1e8 && dist[u] + w < dist[v]){
                    dist[v] = dist[u]+w;
                    updated = true;
                }
            }
            
            if(!updated)break;
        }
        
        //iterate for Vth time 
        for(auto& e:edges){
            int u = e[0];
            int v =e[1];
            int w=e[2];
            
            if(dist[u] != 1e8 && dist[u] + w < dist[v]){
                return {-1};
            }
            
        }
        return dist;
    }
};
