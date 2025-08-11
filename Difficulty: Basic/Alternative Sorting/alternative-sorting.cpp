class Solution {

  public:
    vector<int> alternateSort(vector<int>& arr) {
        // Your code goes here
      
        int n = arr.size();
        vector<int> ans;
         
        sort(arr.begin() , arr.end());
        
        int low = 0 , high = n-1;
        
        while(low <= high){
            if(low != high){
                ans.push_back(arr[high--]);
            ans.push_back(arr[low++]);
            }else{
                ans.push_back(arr[low]);
                break;
            }
        }
        
        return ans;
        
        
    }
};
