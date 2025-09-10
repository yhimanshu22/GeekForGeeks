class Solution {
  public:
    long long numberCount(long long N, long long K) {
        long long lo = 1, hi = N, ans = N + 1;
        
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            
            if (mid - sumDigits(mid) >= K) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        if (ans == N + 1) return 0; // no number satisfies
        return N - ans + 1;
    }
    
  private:
    long long sumDigits(long long x) {
        long long s = 0;
        while (x > 0) {
            s += x % 10;
            x /= 10;
        }
        return s;
    }
};

