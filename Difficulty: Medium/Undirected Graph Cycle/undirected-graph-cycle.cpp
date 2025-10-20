class Solution {
  public:
   int findParent(int node,vector<int>& parent){
            if(parent[node] == node)return node;
            return parent[node] = findParent(parent[node],parent);
        }
        
        bool unionSet(int u,int v,vector<int>& parent,vector<int>& rank){
            int pu = findParent(u,parent);
            int pv = findParent(v,parent);
            
            if(pu == pv)return true;//cycle detected
            
            if(rank[pu] < rank[pv]){
                parent[pu] = pv;
            }else if(rank[pv] < rank[pu]){
                parent[pv] = pu;
            }else{
                parent[pv] = pu;
                rank[pu]++;
            }
            return false;
        }
    bool isCycle(int V, vector<vector<int>>& edges) {
       vector<int> parent(V) ,rank(V,0);
       
       for(int i=0;i<V;i++) parent[i]=i;
       
       for(auto& edge:edges){
           int u = edge[0];
           int v = edge[1];
           
           if(unionSet(u,v,parent,rank))return true;
       }
        return false;
    }
};