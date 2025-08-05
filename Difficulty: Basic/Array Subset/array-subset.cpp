class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        // Your code here
       unordered_map<int,int> mp;
       
       for(int i:a){
           
           mp[i]++;
       }
       
       for(int i:b){
           if(mp[i] == 0)return false;
           mp[i]--;
       }
       return true;
        
    }
};