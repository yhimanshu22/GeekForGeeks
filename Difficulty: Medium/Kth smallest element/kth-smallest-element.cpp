class Solution {
public:
    int kthSmallest(vector<int>& arr, int k) {
        // Step 1: Sort the array
        sort(arr.begin(), arr.end());
        
        // Step 2: Return the k-th smallest element (1-based indexing)
        return arr[k - 1];
    }
};
