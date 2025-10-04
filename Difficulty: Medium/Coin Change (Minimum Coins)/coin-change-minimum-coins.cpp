class Solution {
public:
    int minCoins(vector<int> &coins, int sum) {
        int n = coins.size();
        const int INF = 1e9;
        vector<vector<int>> dp(n+1, vector<int>(sum+1, INF));

        // base case: sum=0 requires 0 coins
        for (int i = 0; i <= n; i++) dp[i][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (coins[i-1] <= j)
                    dp[i][j] = min(dp[i-1][j], 1 + dp[i][j - coins[i-1]]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        return (dp[n][sum] == INF) ? -1 : dp[n][sum];
    }
};
