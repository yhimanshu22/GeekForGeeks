class Solution {
public:
    int nCr(int n, int r) {
        const int mod = 1e9 + 7;
        vector<vector<int>> C(n+1, vector<int>(r+1, 0));

        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= min(i, r); j++) {
                if(j == 0 || j == i)
                    C[i][j] = 1;
                else
                    C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
            }
        }

        return C[n][r];
    }
};
