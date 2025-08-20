class Solution {
  public:
    int calculateFriendliness(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        int ans = 0;
        
        for(int i=0;i<n - 1;i++){
            ans += abs(arr[i] - arr[i+1]);
        }
        
        ans += abs(arr[n-1] - arr[0]);
        return ans;
    }
};
