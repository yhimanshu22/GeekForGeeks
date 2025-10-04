class Solution {
public:
    int maximizeTheCuts(int n, int x, int y, int z) {
        vector<int> dp(n+1, -1);
        dp[0] = 0; // length 0 → 0 segments

        for(int i = 1; i <= n; i++) {
            int a = (i >= x && dp[i-x] != -1) ? dp[i-x] + 1 : -1;
            int b = (i >= y && dp[i-y] != -1) ? dp[i-y] + 1 : -1;
            int c = (i >= z && dp[i-z] != -1) ? dp[i-z] + 1 : -1;
            
            dp[i] = max({a, b, c});
        }

        return max(dp[n], 0); // if no cut possible, return 0
    }
};
