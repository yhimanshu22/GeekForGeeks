class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(helper(i,adj,vis)) return true; 
            }
        }
        
        return false;
        
        
    }
    
    bool helper(int start,vector<vector<int>>& adj , vector<int>& visited ){
        
        queue<pair<int,int>> q;
        q.push({start,-1});
        visited[start] = 1;
        
        while(!q.empty()){
            auto [node,parent] = q.front();
            q.pop();
            
            for(auto nbr : adj[node]){
                if(!visited[nbr]){
                    visited[nbr] = 1;
                    q.push({nbr , node});
                }else if(nbr != parent)return true;
            }
        }
        return false;
    }
};