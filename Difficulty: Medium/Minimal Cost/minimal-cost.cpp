class Solution {
  public:
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
          int n = arr.size();
        vector<int> dp(n, 1e9);
        dp[0] = 0;

        for (int i = 1; i < n; i++) {
            for (int j = max(0, i - k); j < i; j++) {
                dp[i] = min(dp[i], dp[j] + abs(arr[i] - arr[j]));
            }
        }

        return dp[n-1];
    }
};