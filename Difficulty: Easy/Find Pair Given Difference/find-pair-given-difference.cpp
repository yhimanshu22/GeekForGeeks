
class Solution {
  public:
     bool findPair(vector<int> &arr, int diff) {
        unordered_map<int,int> freq;
        for (int x : arr) freq[x]++;

        for (int x : arr) {
            if (diff == 0) {
                // need at least 2 occurrences
                if (freq[x] > 1) return true;
            } else {
                if (freq.count(x + diff) || freq.count(x - diff)) return true;
            }
        }
        return false;
    }
};
