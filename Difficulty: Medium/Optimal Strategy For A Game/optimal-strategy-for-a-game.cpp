class Solution {
  public:
    int maximumAmount(vector<int> &arr) {
        // code here
          int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // length 1
        for (int i = 0; i < n; i++)
            dp[i][i] = arr[i];

        // length 2
        for (int i = 0; i < n-1; i++)
            dp[i][i+1] = max(arr[i], arr[i+1]);

        // length >= 3
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;

                int pick_i = arr[i] + min(dp[i+2][j], dp[i+1][j-1]);
                int pick_j = arr[j] + min(dp[i][j-2], dp[i+1][j-1]);

                dp[i][j] = max(pick_i, pick_j);
            }
        }

        return dp[0][n-1];
    }
};