// User function Template for C++

class Solution {
  public:
    int minimumStep(int n) {
        vector<bool> visited(n+1,false);
        queue<pair<int,int>> q;
        
        q.push({1,0});
        visited[1] = true;
        
        while(!q.empty()){
            auto [node,dist] = q.front();
            q.pop();
            
            if(node == n)return dist;
            
            if(node + 1 <= n && !visited[node + 1]){
                visited[node + 1] = true;
                q.push({node+1,dist+1});
            }
            
            if(node * 3 <= n &&  !visited[node*3]){
                visited[node*3] = true;
                q.push({node*3 , dist +1} );
                
            }
        }
        return -1;
        
    }
};