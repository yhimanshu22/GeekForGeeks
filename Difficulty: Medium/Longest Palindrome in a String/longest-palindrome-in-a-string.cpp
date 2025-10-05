class Solution {
public:
    string longestPalindrome(string &s) {
        int n = s.size();
        string b = s;
        reverse(b.begin(), b.end());

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        int maxLen = 0;
        int endIdx = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == b[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;

                    int revIdx = n - j;
                    if (revIdx + dp[i][j] - 1 == i - 1) {  // check alignment
                        if (dp[i][j] > maxLen) {
                            maxLen = dp[i][j];
                            endIdx = i - 1;
                        }
                    }
                } else {
                    dp[i][j] = 0; // substring pattern
                }
            }
        }

        return s.substr(endIdx - maxLen + 1, maxLen);
    }
};
