class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
         int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(3, 0));

        // Base case: first day
        for (int j = 0; j < 3; j++)
            dp[0][j] = arr[0][j];

        // Fill DP table
        for (int i = 1; i < n; i++) {
            dp[i][0] = arr[i][0] + max(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = arr[i][1] + max(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = arr[i][2] + max(dp[i-1][0], dp[i-1][1]);
        }

        // Maximum points on last day
        return max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    }
};