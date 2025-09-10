class Solution {
  public:
    int findClosest(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == k) return arr[mid]; // exact match
            else if (arr[mid] < k) low = mid + 1;
            else high = mid - 1;
        }

        // Now: high < low
        // Edge cases
        if (low >= n) return arr[n - 1]; // k > all elements
        if (high < 0) return arr[0];     // k < all elements

        // Compare arr[low] (just bigger) and arr[high] (just smaller)
        if ((k - arr[high]) == (arr[low] - k)) {
            return arr[low]; // if tie, return greater
        }
        else if ((k - arr[high]) < (arr[low] - k)) {
            return arr[high];
        }
        else {
            return arr[low];
        }
    }
};
