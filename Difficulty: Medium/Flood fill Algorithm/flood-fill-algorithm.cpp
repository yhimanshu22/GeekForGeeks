class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Code here
           int oldColor = image[sr][sc];
        if (oldColor != newColor) {  // avoid infinite recursion
            dfs(sr, sc, image, oldColor, newColor);
        }
        return image;
    }
    
     void dfs(int x, int y, vector<vector<int>>& image, int oldColor, int newColor){
        int n = image.size();
        int m = image[0].size();
        
        // boundary + same color check
        if (x < 0 || y < 0 || x >= n || y >= m) return;
        if (image[x][y] != oldColor) return;
        
          // change color
        image[x][y] = newColor;
        
        // 4 directions
        dfs(x+1, y, image, oldColor, newColor);
        dfs(x-1, y, image, oldColor, newColor);
        dfs(x, y+1, image, oldColor, newColor);
        dfs(x, y-1, image, oldColor, newColor);
     } 
};