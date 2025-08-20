class Solution {
  public:
    int countElements(vector<int>& arr) {
        // code here
         int cnt = 0;
        int n = arr.size();
        int maxSoFar = INT_MIN;
        
        for(int i = 0; i < n; i++) {
            if(arr[i] > maxSoFar) {
                cnt++;
                maxSoFar = arr[i];
            }
        }
        return cnt;
    }
};
