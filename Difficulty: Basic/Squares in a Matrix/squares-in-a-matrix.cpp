
class Solution {
  public:
    int squaresInMatrix(int m, int n) {
        // code here
         int t = min(m, n);
        long long ans = 0;
        
        for (int k = 1; k <= t; k++) {
            ans += 1LL * (m - k + 1) * (n - k + 1);
        }
        
        return ans;
    }
};