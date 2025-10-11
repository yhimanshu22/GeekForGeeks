class Solution {
  public:
    // Directions: up, down, left, right
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    bool dfs(int x, int y, vector<vector<char>> &mat, string &word, int idx) {
        if(idx == word.size()) return true; // word found
        int n = mat.size();
        int m = mat[0].size();
        
        if(x < 0 || x >= n || y < 0 || y >= m || mat[x][y] != word[idx])
            return false;
        
        char temp = mat[x][y];
        mat[x][y] = '#'; // mark as visited
        
        for(int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(dfs(nx, ny, mat, word, idx + 1))
                return true;
        }
        
        mat[x][y] = temp; // backtrack
        return false;
    }
    
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == word[0] && dfs(i, j, mat, word, 0))
                    return true;
            }
        }
        return false;
    }
};
