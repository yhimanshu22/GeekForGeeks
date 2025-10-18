class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
         int n = arr.size();
    int left = 0, bestLen = 0, bestStart = 0;
    multiset<int> window;

    for (int right = 0; right < n; right++) {
        window.insert(arr[right]);

        // Shrink window until max - min <= x
        while (*window.rbegin() - *window.begin() > x) {
            window.erase(window.find(arr[left]));
            left++;
        }

        // Update best subarray
        if (right - left + 1 > bestLen) {
            bestLen = right - left + 1;
            bestStart = left;
        }
    }

    return vector<int>(arr.begin() + bestStart, arr.begin() + bestStart + bestLen);
    }
};