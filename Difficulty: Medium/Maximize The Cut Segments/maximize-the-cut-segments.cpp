class Solution {
  public:
    // Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z) {
        // Your code here
        vector<int> dp(n+1,-1);
        
        dp[0] =0;
        
        for(int i=1;i<=n;i++){
            int a = (i >= x && dp[i-x] != -1) ? dp[i-x]+1 : -1;
            int b = (i >= y && dp[i-y] != -1) ? dp[i-y]+1 : -1;
            int c = ( i >= z && dp[i-z] != -1 ) ? dp[i-z]+1 : -1;
            
            dp[i]= max({a,b,c});
        }
        return dp[n] == -1 ? 0 : dp[n];
    }
};