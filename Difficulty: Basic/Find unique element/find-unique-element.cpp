class Solution {
  public:
    int findUnique(int k, vector<int>& arr) {
        // code here
        unordered_map<int,int> map;
        int n = arr.size();
        
        for(int i=0;i<n;i++){
            map[arr[i]]++;
        }
        
        for(auto it:map){
            if(it.second == 1)return it.first;
        }
        
        return -1;
    }
};