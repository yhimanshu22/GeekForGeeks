class Solution {
public:
    int N, M;
    
    void dfs(int i, int j, vector<vector<int>>& mat) {
        if (i < 0 || i >= N || j < 0 || j >= M || mat[i][j] == 0)
            return;
        mat[i][j] = 0; // mark visited
        dfs(i+1, j, mat);
        dfs(i-1, j, mat);
        dfs(i, j+1, mat);
        dfs(i, j-1, mat);
    }
    
    int closedIslands(vector<vector<int>>& mat, int n, int m) {
        N = n; M = m;
        
        // Step 1: Eliminate 1s connected to borders
        for (int i = 0; i < N; i++) {
            if (mat[i][0] == 1) dfs(i, 0, mat);
            if (mat[i][M-1] == 1) dfs(i, M-1, mat);
        }
        for (int j = 0; j < M; j++) {
            if (mat[0][j] == 1) dfs(0, j, mat);
            if (mat[N-1][j] == 1) dfs(N-1, j, mat);
        }
        
        // Step 2: Count closed islands
        int count = 0;
        for (int i = 1; i < N-1; i++) {
            for (int j = 1; j < M-1; j++) {
                if (mat[i][j] == 1) {
                    dfs(i, j, mat);
                    count++;
                }
            }
        }
        
        return count;
    }
};
