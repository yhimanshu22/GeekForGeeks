class Solution {
public:
    int count(vector<int>& coins, int sum) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));

        // base case: sum=0 can always be formed
        for (int i = 0; i <= n; i++) dp[i][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (coins[i-1] <= j)
                    dp[i][j] = dp[i-1][j] + dp[i][j - coins[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        return dp[n][sum];
    }
};
