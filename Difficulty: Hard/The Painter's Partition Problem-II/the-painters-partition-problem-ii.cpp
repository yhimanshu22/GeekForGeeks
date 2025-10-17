class Solution {
public:
    bool isPossible(vector<int>& arr, int k, int mid) {
        int workers = 1, currSum = 0;

        for (int time : arr) {
            if (time > mid) return false; // single element too big
            if (currSum + time <= mid) {
                currSum += time;
            } else {
                workers++;
                currSum = time;
            }
        }

        return workers <= k;
    }

    int minTime(vector<int>& arr, int k) {
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(arr, k, mid)) {
                ans = mid;
                high = mid - 1; // try smaller maximum
            } else {
                low = mid + 1;  // need bigger maximum
            }
        }

        return ans;
    }
};
