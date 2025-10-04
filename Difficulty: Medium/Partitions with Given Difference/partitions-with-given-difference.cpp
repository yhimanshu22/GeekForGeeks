class Solution {
public:
    int countPartitions(vector<int>& arr, int d) {
        int n = arr.size();
        int total = 0;
        const int mod = 1e9 + 7;

        for (int x : arr) total += x;

        if (total < d || (total + d) % 2 != 0) return 0;

        int target = (total + d) / 2;

        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));

        for (int i = 0; i <= n; i++) dp[i][0] = 1; // sum=0 can always be formed

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                if (arr[i-1] <= j)
                    dp[i][j] = (dp[i-1][j] + dp[i-1][j - arr[i-1]]) % mod;
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        return dp[n][target];
    }
};
