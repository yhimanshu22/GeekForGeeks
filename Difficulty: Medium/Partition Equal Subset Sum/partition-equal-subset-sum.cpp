class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        // code here
        int n = arr.size();
        int sum = 0;
        for(int x:arr)sum+=x;
        
        if(sum % 2 == 1)return false;
        
        sum = sum/2;
        
        vector<vector<int>> dp(n+1,vector<int>(sum+1,false));
        
        for(int i=0;i<=n;i++)dp[i][0] = true;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]]; 
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
};