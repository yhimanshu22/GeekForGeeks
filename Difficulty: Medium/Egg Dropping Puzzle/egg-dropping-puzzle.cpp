class Solution {
  public:

    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int eggDrop(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        // Base cases
        for (int i = 1; i <= n; i++) {
            dp[i][0] = 0; // 0 floor
            dp[i][1] = 1; // 1 floor
        }

        for (int j = 1; j <= k; j++)
            dp[1][j] = j; // 1 egg

        // Fill DP table
        for (int i = 2; i <= n; i++) {
            for (int j = 2; j <= k; j++) {
                dp[i][j] = INT_MAX;
                int low = 1, high = j;

                // Binary search optimization
                while (low <= high) {
                    int mid = (low + high) / 2;
                    int breaks = dp[i - 1][mid - 1];
                    int survives = dp[i][j - mid];
                    int temp = 1 + max(breaks, survives);
                    dp[i][j] = min(dp[i][j], temp);

                    if (breaks < survives)
                        low = mid + 1;
                    else
                        high = mid - 1;
                }
            }
        }

        return dp[n][k];
    }
};