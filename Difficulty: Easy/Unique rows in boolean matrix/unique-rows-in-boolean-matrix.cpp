class Solution {
  public:
    // #define MAX 1000
    vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col) {
        // Your code here
        vector<vector<int>> ans;
        set<vector<int>> seen;
        
        for(int i=0;i<row;i++){
            vector<int> temp;
            for(int j=0;j<col;j++){
                temp.push_back(M[i][j]);
            }
            
            if(seen.insert(temp).second){
                ans.push_back(temp);
            }
        }
        
        return ans;
        
    }
};