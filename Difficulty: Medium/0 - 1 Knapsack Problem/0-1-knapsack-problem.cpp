class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        // DP table of size (n+1) x (W+1)
        vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

        // Build table dp[][] iteratively
        for(int i = 1; i <= n; i++) {
            for(int w = 1; w <= W; w++) {
                if(wt[i-1] <= w) {
                    // Include or exclude the current item
                    dp[i][w] = max(val[i-1] + dp[i-1][w - wt[i-1]], dp[i-1][w]);
                } else {
                    // Cannot include current item
                    dp[i][w] = dp[i-1][w];
                }
            }
        }
        return dp[n][W]; // maximum value possible
    }
};
