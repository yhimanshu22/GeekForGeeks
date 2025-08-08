class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int V = adj.size();
        vector<int> ans;
        vector<bool> visited(V , false);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                helper(i,adj,ans,visited);
            }
        }
        
        return ans;
        
    }
    
    void helper(int node,vector<vector<int>>& adj , vector<int>& ans , vector<bool>& visited){
        visited[node] = true;
        ans.push_back(node);
        
       for(auto it:adj[node]){
           if(!visited[it]){
               helper(it,adj,ans,visited);
           }
       }
    }
};