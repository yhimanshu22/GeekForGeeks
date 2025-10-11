class Solution {
public:
    void dfs(int x, int y, vector<vector<char>>& mat, vector<vector<int>>& vis) {
        int n = mat.size();
        int m = mat[0].size();
        vis[x][y] = 1;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        for(int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(nx >= 0 && ny >= 0 && nx < n && ny < m && 
               mat[nx][ny] == 'O' && !vis[nx][ny]) {
                dfs(nx, ny, mat, vis);
            }
        }
    }

    vector<vector<char>> fill(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Step 1: Mark all 'O's connected to the boundary
        for(int i = 0; i < n; i++) {
            if(mat[i][0] == 'O' && !vis[i][0]) dfs(i, 0, mat, vis);
            if(mat[i][m-1] == 'O' && !vis[i][m-1]) dfs(i, m-1, mat, vis);
        }

        for(int j = 0; j < m; j++) {
            if(mat[0][j] == 'O' && !vis[0][j]) dfs(0, j, mat, vis);
            if(mat[n-1][j] == 'O' && !vis[n-1][j]) dfs(n-1, j, mat, vis);
        }

        // Step 2: Replace all unvisited 'O's with 'X'
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 'O' && !vis[i][j])
                    mat[i][j] = 'X';
            }
        }

        return mat;
    }
};
