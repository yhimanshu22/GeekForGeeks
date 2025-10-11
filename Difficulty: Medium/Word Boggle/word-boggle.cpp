class Solution {
  public:
    int n, m;
    vector<vector<int>> vis;
    vector<vector<char>> board;
    
    // Directions: 8 possible moves
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    // DFS helper function
    bool dfs(int x, int y, string &word, int idx) {
        if (idx == word.size()) return true;  // Word found
        
        if (x < 0 || y < 0 || x >= n || y >= m || vis[x][y] || board[x][y] != word[idx])
            return false;

        vis[x][y] = 1;
        for (int k = 0; k < 8; k++) {
            if (dfs(x + dx[k], y + dy[k], word, idx + 1)) {
                vis[x][y] = 0;
                return true;
            }
        }
        vis[x][y] = 0;
        return false;
    }

    bool exist(string &word) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    vis.assign(n, vector<int>(m, 0));
                    if (dfs(i, j, word, 0)) return true;
                }
            }
        }
        return false;
    }

    vector<string> wordBoggle(vector<vector<char>> &b, vector<string> &dictionary) {
        board = b;
        n = board.size();
        m = board[0].size();
        set<string> ans;

        for (auto &word : dictionary) {
            if (exist(word)) ans.insert(word);
        }

        return vector<string>(ans.begin(), ans.end());
    }
};
