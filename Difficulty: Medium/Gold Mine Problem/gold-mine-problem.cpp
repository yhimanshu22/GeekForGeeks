class Solution {
public:
    int maxGold(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Fill last column
        for (int i = 0; i < m; i++) dp[i][n-1] = mat[i][n-1];

        // Fill DP table from second last column to first
        for (int j = n - 2; j >= 0; j--) {
            for (int i = 0; i < m; i++) {
                int right = dp[i][j+1];
                int right_up = (i > 0) ? dp[i-1][j+1] : 0;
                int right_down = (i < m-1) ? dp[i+1][j+1] : 0;

                dp[i][j] = mat[i][j] + max({right, right_up, right_down});
            }
        }

        // Maximum gold starting from any row in first column
        int maxGold = 0;
        for (int i = 0; i < m; i++) maxGold = max(maxGold, dp[i][0]);

        return maxGold;
    }
};
