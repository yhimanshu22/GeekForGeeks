class Solution {

  public:
    int minDifference(vector<int>& arr) {
        // Your code goes here
        int n = arr.size();
        int total = 0;
        for(int x:arr)total+=x;
        
        int target = total/2;
        
        vector<vector<int>> dp(n+1,vector<int>(target+1,false));
        
        for(int i=0;i<=n;i++)dp[i][0]=true;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                    
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        int s1=0;
        for(int i=target;i>=0;i--){
            if(dp[n][i]){
                s1=i;
                break;
            }
        }
        
        return total-2*s1;
    }
};
