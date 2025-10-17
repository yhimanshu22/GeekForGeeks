class Solution {
public:
    unordered_map<string,int> dp;

    int solve(string &s, int i, int j, bool isTrue) {
        if (i > j) return 0;

        string key = to_string(i) + "_" + to_string(j) + "_" + to_string(isTrue);
        if (dp.find(key) != dp.end()) return dp[key];

        if (i == j) {
            if (isTrue) return s[i] == 'T';
            else return s[i] == 'F';
        }

        int ways = 0;
        for (int k = i + 1; k <= j - 1; k += 2) { // operators at odd positions
            int LT = solve(s, i, k - 1, true);
            int LF = solve(s, i, k - 1, false);
            int RT = solve(s, k + 1, j, true);
            int RF = solve(s, k + 1, j, false);

            char op = s[k];
            if (op == '&') {
                if (isTrue) ways += LT * RT;
                else ways += LT*RF + LF*RT + LF*RF;
            } else if (op == '|') {
                if (isTrue) ways += LT*RT + LT*RF + LF*RT;
                else ways += LF*RF;
            } else if (op == '^') {
                if (isTrue) ways += LT*RF + LF*RT;
                else ways += LT*RT + LF*RF;
            }
        }

        return dp[key] = ways;
    }

    int countWays(string &s) {
        dp.clear();
        return solve(s, 0, s.size() - 1, true);
    }
};
