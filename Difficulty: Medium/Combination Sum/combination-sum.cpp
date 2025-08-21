// User function template for C++

class Solution {
  public:
  vector<vector<int>> ans;
  vector<int> temp;
  int n;
    
    void backtrack(vector<int> &arr , int idx ,int target){
        
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(target < 0 || idx == arr.size())return;
        
        temp.push_back(arr[idx]);
        backtrack(arr,idx,target - arr[idx]);
        temp.pop_back();
        
        backtrack(arr,idx+1,target);
        
    }
    
    vector<vector<int>> combinationSum(vector<int> &arr, int target) {
        n = arr.size();
        ans.clear();
        temp.clear();
        backtrack(arr, 0, target);
        return ans;
        
    }
};