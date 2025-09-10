class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        
        for(auto &e:edges){
            int u = e[0],v = e[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u); //undirected graph
        }
        
        vector<bool> visited(V,false);
        
        //bfs traversal
        for(int start=0;start < V;start++){
            if(!visited[start]){
                queue<pair<int,int>> q; // {node, parent}
                q.push({start,-1});
                 visited[start] = true; // mark visited here
                while(!q.empty()){
                    auto[node,parent] = q.front();
                    q.pop();
                    
                    for(int neigh:adj[node]){
                        if(!visited[neigh]){
                            visited[neigh] = true;
                            q.push({neigh, node});
                        }else if(neigh != parent){
                            return true;// already visited & not parent → cycle
                        }
                    }
                }
                
            }
        }
        return false;
    }
};