// User function Template for C++

class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i <= j){
                    dp[i][j]  = max(dp[i-1][j] , price[i-1]+dp[i][j-i]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][n];
    }
};