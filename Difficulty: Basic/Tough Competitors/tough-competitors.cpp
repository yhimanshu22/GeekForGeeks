class Solution {
  public:
    int minDiff(vector<int>& arr) {
        // code here
        int ans = INT_MAX;
        int n = arr.size();
          sort(arr.begin(), arr.end());
        
        
        for(int i=0;i<n;i++){
            int diff =abs( arr[i] - arr[i+1]);
            ans = min(ans,diff);
        }
        
        return ans;
    }
};
