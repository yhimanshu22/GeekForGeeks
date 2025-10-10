class Solution {
public:
    int orangesRotting(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        queue<pair<int,int>> q;
        int fresh = 0;
        
        // Initialize queue with rotten oranges & count fresh oranges
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 2){
                    q.push({i,j});
                } else if(mat[i][j] == 1){
                    fresh++;
                }
            }
        }
        
        if(fresh == 0) return 0;
        
        int time = 0;
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        
        while(!q.empty()){
            int sz = q.size();
            bool rottedThisRound = false;
            
            for(int i=0;i<sz;i++){
                auto [x,y] = q.front(); q.pop();
                
                for(int k=0;k<4;k++){
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] == 1){
                        mat[nx][ny] = 2;
                        fresh--;
                        q.push({nx,ny});
                        rottedThisRound = true;
                    }
                }
            }
            
            if(rottedThisRound) time++;
        }
        
        return fresh == 0 ? time : -1;
    }
};
