class Solution {
  public:
    int findMin(int n) {
        // code here
        vector<int> coins = {1, 2, 5, 10};
        vector<int> dp(n+1, 1e9);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int coin : coins) {
                if (i - coin >= 0)
                    dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }

        return dp[n];
    }
};