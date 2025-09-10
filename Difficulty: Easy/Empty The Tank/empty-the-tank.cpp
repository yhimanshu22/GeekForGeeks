// User function Template for C++
class Solution {
  public:
    long long int minDaysToEmpty(long long int C, long long int l) {
        // code here
       long long water = C;
         for (long long day = 1; ; ++day) {
            water -= day;               // drink at end of current day
            if (water <= 0) return day; // becomes empty on this day
            water = min(C, water +l);  // refill (bounded by capacity)
        }
        // unreachable
        return -1;
        
    }
};