// User function Template for C++

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> visited(V,0);
        int cnt=0;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,adj,visited,V);
                cnt++;
            }
        }
        return cnt;
        
    }
    
    void dfs(int node,vector<vector<int>>& adj,vector<int>& visited,int V){
        visited[node] = 1;
        for(int j=0;j<V;j++){
            if(!visited[j] && adj[node][j] == 1){
                dfs(j,adj,visited,V);
            }
        }
    }
};