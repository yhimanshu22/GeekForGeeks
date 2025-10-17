class Solution {
public:
    vector<long long> dp;

    long long catalan(int n) {
        if (n <= 1) return 1;   // base cases

        if (dp[n] != -1) return dp[n];

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += catalan(i) * catalan(n - 1 - i);
        }

        return dp[n] = ans;
    }

    int findCatalan(int n) {
        dp.assign(n + 1, -1);  // initialize memo table
        return catalan(n);
    }
};
