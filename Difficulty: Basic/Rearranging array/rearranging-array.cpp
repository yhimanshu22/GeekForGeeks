

class Solution {
  public:
    vector<int> Rearrange(vector<int> arr) {
        // code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<int> ans(n);

        int left = 0, right = n - 1;
        // Use a counter to track position in ans
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                ans[i] = arr[left++];
            } else {
                ans[i] = arr[right--];
            }
        }

        return ans;
    }
};