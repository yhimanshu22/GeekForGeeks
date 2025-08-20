

class Solution {
  public:
    int shortestUnorderedSubarray(vector<int>& arr) {
         int n = arr.size();
        
        // Check if array is strictly increasing
        bool increasing = true, decreasing = true;
        for(int i = 1; i < n; i++) {
            if(arr[i] <= arr[i-1]) increasing = false;
            if(arr[i] >= arr[i-1]) decreasing = false;
        }
        
        if(increasing || decreasing) return 0;
        return 3;
    }
};