// User function template for C++

class Solution {
  public:
    // Function to return list containing first n fibonacci numbers.
    vector<int> fibonacciNumbers(int n) {
        // code here
        vector<int> dp(n,0);
        
        if(n<=0)return {};
        
        dp[0]=0;
        dp[1]=1;
        
        for(int i=2;i<n;i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        
        return dp;
    }
};