// User function Template for C++

class Solution {
 public:
    int countPartitions(vector<int>& arr, int d) {
        int n = arr.size();
        int total = 0;
        int mod = 1e9 + 7; // Use 1e9 + 7 for competitive programming modulo
        
        for (int x : arr) {
            total += x;
        }
        
        // 1. Initial Checks
        // Target = (TotalSum + d) / 2.
        // If (TotalSum + d) is odd OR if TargetSum is negative (TotalSum < d), return 0.
        if (total < d || (total + d) % 2 != 0) {
            return 0;
        }
        
        // 2. 🚨 CORRECTION: Calculate the Target Sum (Sum of S1)
        int target = (total + d) / 2;
        
        // 3. DP Table Setup
        // dp[i][j]: Number of ways to form sum j using the first i elements.
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        
        // 4. 🚨 CORRECTION: Base Case (Sum 0 is possible in 1 way, using 0 items as well)
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        
        // 5. Fill DP Table (Subset Sum Logic)
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                
                // If the current element (arr[i-1]) is small enough to be included
                if (arr[i - 1] <= j) {
                    // Include (arr[i-1] + ways for remaining sum) + Exclude (ways without arr[i-1])
                    dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - arr[i - 1]]) % mod;
                } else {
                    // Exclude the current element
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        // Result is the number of ways to form the TargetSum using all elements
        return dp[n][target];
    }
};