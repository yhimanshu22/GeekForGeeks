class Solution {
public:
    int minDifference(vector<int>& arr) {
        int n = arr.size();
        int total = 0;
        for(int x : arr) total += x;

        vector<vector<bool>> dp(n+1, vector<bool>(total+1, false));

        for(int i = 0; i <= n; i++) dp[i][0] = true;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= total; j++){
                if(arr[i-1] <= j)
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        int diff = total;
        for(int j = 0; j <= total/2; j++){
            if(dp[n][j])
                diff = min(diff, total - 2*j);
        }

        return diff;
    }
};
