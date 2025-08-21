class Solution {
  public:
  vector<string> ans;
  int n;
  
  void dfs(int i,int j ,string path , vector<vector<int>>& maze ,vector<vector<int>>& visited){
      
       if(i == n-1 && j == n-1) {
            ans.push_back(path);
            return;
        }
      
      visited[i][j] = 1;
      
      // Down
      if(i+1 < n && !visited[i+1][j] && maze[i+1][j] == 1){
          dfs(i+1,j,path + "D" , maze , visited);
      }
      
      // Up
      if(i-1 >= 0 && !visited[i-1][j] && maze[i-1][j] == 1){
          dfs(i-1,j,path + "U" ,maze,visited);
      }
      
      // Right
      if(j+1 < n && !visited[i][j+1] && maze[i][j+1] == 1){
          dfs(i,j+1,path + "R",maze,visited);
      }
      
      // Left
      if(j-1 >= 0 && !visited[i][j-1] && maze[i][j-1] == 1){
          dfs(i,j-1,path + "L" , maze , visited);
      }
      
      visited[i][j] = 0;
  }
  
  vector<string> ratInMaze(vector<vector<int>>& maze) {
        n = maze.size();
        ans.clear();
        vector<vector<int>> visited(n , vector<int>(n,0));
        
        if(maze[0][0] == 0 || maze[n-1][n-1] == 0) return ans;
        
        dfs(0,0,"" , maze,visited);
        sort(ans.begin() ,ans.end());
        return ans;
  }
};
