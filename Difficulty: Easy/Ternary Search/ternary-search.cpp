class Solution {
  public:
    int findMinIndex(vector<int>& arr) {
         int n = arr.size();
        if (n == 0) return -1;       // defensive
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] > arr[mid + 1]) {
                // we are on decreasing slope -> min is to the right
                l = mid + 1;
            } else {
                // we are on increasing slope or at valley -> min is at mid or left
                r = mid;
            }
        }
        return l; // index of minimum
    }
};
