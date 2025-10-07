class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) {
        // code here
        int n = coins.size();
    
        vector<vector<int>> dp(n+1,vector<int>(sum+1,1e9));
        
        for(int i=0;i<=n;i++){
            dp[i][0] = 0;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(coins[i-1] <= j){
                    dp[i][j] = min(dp[i-1][j] , 1+ dp[i][j-coins[i-1]]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][sum] == 1e9 ? -1 : dp[n][sum];
    }
};