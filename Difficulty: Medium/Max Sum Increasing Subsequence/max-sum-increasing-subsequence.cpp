class Solution {
public:
    int maxSumIS(vector<int>& arr) {
        int n = arr.size();
        
        if (n == 0) {
            return 0; // Max sum is 0 for an empty array.
        }
        
        // dp[i] stores the maximum sum of an increasing subsequence *ending* at index i.
        // The vector size must be n to match array indices 0 to n-1.
        vector<int> dp(n); 
        
        int max_total_sum = 0;
        
        // Iterate through all elements (from 0 to n-1)
        for (int i = 0; i < n; i++) {
            
            // 1. Base initialization: Max sum ending at i is at least arr[i] itself.
            dp[i] = arr[i];
            
            // 2. Iterate over previous elements (j < i)
            for (int j = 0; j < i; j++) {
                
                // If arr[i] can extend the subsequence ending at arr[j]
                if (arr[j] < arr[i]) {
                    
                    // Recurrence: Update dp[i] by checking if (arr[i] + dp[j]) 
                    // is greater than the current dp[i] value.
                    // This is the maximum sum we can get by extending the subsequence ending at j.
                    dp[i] = max(dp[i], arr[i] + dp[j]);
                }
            }
            
            // 3. Update the overall maximum sum found so far
            max_total_sum = max(max_total_sum, dp[i]);
        }
        
        return max_total_sum;
    }
};