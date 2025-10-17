class Solution {
  public:
    string longestPalindrome(string &s) {
       
        int n =s.size();
        string b  = s;
        reverse(b.begin(),b.end());
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        int maxLength = 0;
        int endInd = 0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1] == b[j-1]){
                    dp[i][j] = 1+ dp[i-1][j-1];
                    
                    int startInOriginal = n - j;
                    
                    if(startInOriginal + dp[i][j] - 1 == i-1){
                       if(dp[i][j] > maxLength){
                        maxLength = dp[i][j];
                        endInd = i-1;
                       }
                    }
                    
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        
         return s.substr(endInd - maxLength + 1, maxLength);

        
    }
};