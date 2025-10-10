class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Code here
        int old = image[sr][sc];
        
        if(old != newColor){
            dfs(image,sr,sc,old,newColor);
        }
        
        return image;
        
    }
    
    void dfs(vector<vector<int>>& image,int sr,int sc,int old,int newColor){
        
       
        int n = image.size();
        int m= image[0].size();
        
        if(sr<0 || sr >= n || sc < 0 || sc >= m)return ;
        if(image[sr][sc]!= old)return;
        
         image[sr][sc] = newColor;
        
        
        dfs(image,sr-1,sc,old,newColor);
        dfs(image,sr+1,sc,old,newColor);
        dfs(image,sr,sc-1,old,newColor);
        dfs(image,sr,sc+1,old,newColor);
        
    }
    
    
};