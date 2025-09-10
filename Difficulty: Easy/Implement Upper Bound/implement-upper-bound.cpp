class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        // code here
         int n = arr.size();
        int low = 0, high = n - 1;
        int ans = n;  // default = n (if no element > target)

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] > target) {
                ans = mid;
                high = mid - 1; // search left side
            } else {
                low = mid + 1; // search right side
            }
        }

        return ans;
    }
};
