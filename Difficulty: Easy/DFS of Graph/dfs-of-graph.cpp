class Solution {
  public:
  
   void helper(int node,vector<vector<int>>& adj,vector<int>& list,vector<int>& vis){
       vis[node] = 1;
       list.push_back(node);
       
       for(auto it:adj[node]){
           if(!vis[it]){
               helper(it,adj,list,vis);
           }
       }
       
   }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n =adj.size();
        
        vector<int> list;
        vector<int> vis(n,0);
        
        helper(0,adj,list,vis);
        
        return list;
    }
};