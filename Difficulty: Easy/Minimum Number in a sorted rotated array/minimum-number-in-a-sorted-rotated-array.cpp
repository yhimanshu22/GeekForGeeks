class Solution {
  public:
    // Function to find the minimum element in sorted and rotated array.
    int minNumber(int arr[], int low, int high) {
        // Your code here
        while (low < high) {
            int mid = low + (high - low) / 2;

            // If right half is sorted, min is in left half (including mid)
            if (arr[mid] <= arr[high]) {
                high = mid;
            } else {
                // If left half is sorted, min must be in right half
                low = mid + 1;
            }
        }
        return arr[low]; // low == high (index of min element)
    }
};