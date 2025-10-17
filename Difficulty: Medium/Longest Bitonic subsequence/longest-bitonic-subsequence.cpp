class Solution {
public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        vector<int> LIS(n, 1);
        vector<int> LDS(n, 1);

        // Compute LIS for each index
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i])
                    LIS[i] = max(LIS[i], LIS[j] + 1);
            }
        }

        // Compute LDS for each index
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (nums[j] < nums[i])
                    LDS[i] = max(LDS[i], LDS[j] + 1);
            }
        }

        // Compute max bitonic subsequence
         int maxLen = 0;
        for (int i = 0; i < n; i++) {
            if (LIS[i] > 1 && LDS[i] > 1) // strictly bitonic
                maxLen = max(maxLen, LIS[i] + LDS[i] - 1);
        }


        return maxLen;
    }
};
