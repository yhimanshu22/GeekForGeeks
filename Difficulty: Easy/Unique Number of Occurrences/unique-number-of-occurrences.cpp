// User function Template for C++
class Solution {
  public:
    bool isFrequencyUnique(int n, int arr[]) {
       
       unordered_map<int,int> map;
       
       for(int i=0;i< n ;i++){
           map[arr[i]]++;
       }
       
       set<int> ans;
       
       for(auto it:map){
           if(ans.find(it.second) != ans.end())return false;
           ans.insert(it.second);
       }
       
       return true;
    }
};