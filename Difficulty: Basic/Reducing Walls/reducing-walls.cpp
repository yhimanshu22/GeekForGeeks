// Function to count the number of walls that need to be reduced.
class Solution {
  public:
    int reducingWalls(vector<int>& arr, int k) {
        int cnt = 0;
        int n = arr.size();
       for (int i = 0; i < n; i++) {
            if (arr[i] > k) {
                cnt += (arr[i] - k + k - 1) / k;  // ceiling division
            }
        }
        return cnt;
        
    }
};