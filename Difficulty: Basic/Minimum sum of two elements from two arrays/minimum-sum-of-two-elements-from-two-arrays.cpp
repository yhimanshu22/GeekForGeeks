class Solution {
  public:
    int minSum(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
         int min1 = INT_MAX, min2 = INT_MAX, idx1 = -1;
        for (int i = 0; i < n; i++) {
            if (arr1[i] < min1) {
                min2 = min1;
                min1 = arr1[i];
                idx1 = i;
            } else if (arr1[i] < min2) {
                min2 = arr1[i];
            }
        }
        
        // Find smallest and second smallest in arr2
        int min3 = INT_MAX, min4 = INT_MAX, idx2 = -1;
        for (int i = 0; i < n; i++) {
            if (arr2[i] < min3) {
                min4 = min3;
                min3 = arr2[i];
                idx2 = i;
            } else if (arr2[i] < min4) {
                min4 = arr2[i];
            }
        }
        
        // If smallest elements are from different indices
        if (idx1 != idx2) {
            return min1 + min3;
        }
        
        // Otherwise, take the next best option
        return min(min1 + min4, min2 + min3);
    }
};
