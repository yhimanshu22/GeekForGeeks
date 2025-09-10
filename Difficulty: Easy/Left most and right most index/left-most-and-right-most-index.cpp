class Solution {
  public:
    pair<long, long> indexes(vector<long long> v, long long x) {
        int n = v.size();
        long long first = -1, last = -1; // ✅ correct declaration

        // Find first occurrence
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (v[mid] == x) {
                first = mid;
                high = mid - 1; // keep searching left
            } else if (v[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        // Find last occurrence
        low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (v[mid] == x) {
                last = mid;
                low = mid + 1; // keep searching right
            } else if (v[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return {first, last};
    }
};
