class Solution {
  public:
    bool solve(int start, string &s, unordered_set<string> &dict, vector<int> &dp) {
        if (start == s.size()) return true; // reached end successfully
        if (dp[start] != -1) return dp[start]; // memoized result

        for (int end = start; end < s.size(); end++) {
            string word = s.substr(start, end - start + 1);
            if (dict.count(word) && solve(end + 1, s, dict, dp))
                return dp[start] = true;
        }
        return dp[start] = false;
    }

    bool wordBreak(string &s, vector<string> &dictionary) {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        vector<int> dp(s.size(), -1);  // -1 means uncomputed
        return solve(0, s, dict, dp);
    }
};
