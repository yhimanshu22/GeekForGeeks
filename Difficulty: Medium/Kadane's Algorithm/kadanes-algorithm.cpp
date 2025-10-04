class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int n = arr.size();
        vector<int>dp(n+1,0);
        
        dp[0] = arr[0];
        int maxSum = dp[0];
        
         for (int i = 1; i < n; i++) {
            dp[i] = max(arr[i], dp[i-1] + arr[i]);
            maxSum = max(maxSum, dp[i]);
        }

        
        return maxSum;
    }
};