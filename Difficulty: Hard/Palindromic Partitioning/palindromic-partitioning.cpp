// User function Template for C++

class Solution {
  public:
    int palPartition(string &s) {
        // code here
         int n = s.size();
        vector<int> dp(n, 0);

        for (int i = 0; i < n; i++)
            dp[i] = i;  // maximum possible cuts

        for (int center = 0; center < n; center++) {
            // Odd-length palindrome
            expand(center, center, s, dp);
            // Even-length palindrome
            expand(center, center + 1, s, dp);
        }

        return dp[n - 1];
    }
    
     void expand(int left, int right, string &s, vector<int> &dp) {
        int n = s.size();
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (left == 0)
                dp[right] = 0;
            else
                dp[right] = min(dp[right], dp[left - 1] + 1);
            left--;
            right++;
        }
    }
};