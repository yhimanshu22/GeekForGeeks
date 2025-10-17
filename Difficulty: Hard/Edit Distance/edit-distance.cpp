class Solution {
  public:
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        // code here
        int n = s1.size();
        int m = s2.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=0;i<=n;i++)dp[i][0] = i; //for removing
        for(int j=0;j<=m;j++)dp[0][j] = j; //for inserting 
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = 1 + min({dp[i-1][j] , dp[i][j-1] , dp[i-1][j-1]});
                }
            }
        }
        
        return dp[n][m];
        
    }
};