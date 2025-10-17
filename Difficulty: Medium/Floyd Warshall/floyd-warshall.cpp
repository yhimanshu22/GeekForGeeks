// User function template for C++

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
      
        int V = dist.size();
        const int INF = 100000000;
        
        for(int k=0;k< V ; k++){
            for(int i=0;i<V ; i++){
                for(int j =0;j< V ; j++){
                    if(dist[i][k] != INF && dist[k][j] != INF){
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
    }
};