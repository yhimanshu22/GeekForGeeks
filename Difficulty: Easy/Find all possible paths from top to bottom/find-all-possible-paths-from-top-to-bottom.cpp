// User function Template for C++

class Solution {
  public:
  vector<vector<int>> ans;
  vector<int> path;
  
  void dfs(int i,int j,int n,int m ,vector<vector<int>> &grid){
      
      path.push_back(grid[i][j]);
      
      if(i == n-1 && j == m-1){
          ans.push_back(path);
      }
      
      if(i+1<n)dfs(i+1,j,n,m,grid);
      if(j+1<m)dfs(i,j+1,n,m,grid);
      
      path.pop_back();
  }
  
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid) {
        // code here
      dfs(0,0,n,m,grid);
      return ans;
        
    }
};