//Back-end complete function Template for C++

class Solution {
  public:
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int> ans(n,-1);
        set<int> set;
        
        for(int i=n-1;i>=0;i--){
            auto it = set.upper_bound(arr[i]);
            if(it != set.end())ans[i] = *it;
            set.insert(arr[i]);
        }
        return ans;
        
    }
};