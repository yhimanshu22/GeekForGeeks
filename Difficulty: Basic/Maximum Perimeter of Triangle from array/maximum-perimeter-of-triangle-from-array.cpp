class Solution {
  public:
    int maxPerimeter(vector<int> &arr) {
         sort(arr.begin(), arr.end(), greater<int>()); // sort descending
        int n = arr.size();
        
        for (int i = 0; i < n-2; i++) {
            int a = arr[i], b = arr[i+1], c = arr[i+2];
            if (b + c > a) { // triangle condition
                return a + b + c;
            }
        }
        return -1; // no valid triangle
        
    }
};