class Solution {
public:
    bool equalPartition(vector<int>& arr) {
        int n = arr.size();
        int total = 0;
        for (int x : arr) total += x;

        // odd sum cannot be partitioned equally
        if (total % 2 != 0) return false;

        int sumHalf = total / 2;

        vector<vector<bool>> dp(n+1, vector<bool>(sumHalf+1, false));

        // sum=0 can always be formed
        for (int i = 0; i <= n; i++) dp[i][0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sumHalf; j++) {
                if (arr[i-1] <= j)
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        return dp[n][sumHalf];
    }
};
