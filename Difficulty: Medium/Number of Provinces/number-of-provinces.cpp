// User function Template for C++

class Solution {
  public:
    
    void dfs(int node,vector<int> adjLs[],vector<int>& vis){
         vis[node] = 1;
         
         for(auto it: adjLs[node]){
             if(!vis[it]){
                 dfs(it,adjLs,vis);
             }
         }
    }
    
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> adjLs[V];
        
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(i != j && adj[i][j] == 1 ){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
            
        }
        
        int cnt = 0;
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adjLs,vis);
            }
        }
        
        return cnt;
        
    }
};