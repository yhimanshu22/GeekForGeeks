
class Solution {
  public:
    int specialIntegers(int n, vector<int> &arr) {
        // code here
       unordered_set<int> s(arr.begin(), arr.end()); // store unique elements
        int count = 0;

        for (int num : s) {
            if (s.count(num - 1) && s.count(num) && s.count(num + 1)) {
                count++;
            }
        }
        return count;
    }
};
