// User function Template for C++

class Solution {
  public:
    int minTime(int S1, int S2, int N) {
        // code here
        long long lo = min(S1, S2); 
        long long hi = min(S1, S2) * N;
        long long ans = hi;
        
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            
            long long docs = (mid / S1) + (mid / S2);
            
            if (docs >= N) {
                ans = mid;
                hi = mid - 1;  // try smaller time
            } else {
                lo = mid + 1;  // need more time
            }
        }
        return ans;
    }
};