class Solution {
  public:
  
    vector<string> ans;
    int n;
    
    void backtrack(string &s , int idx){
        if(idx == n){
            ans.push_back(s);
            return;
        }
        
        unordered_set<char> used;
        
        for(int i= idx;i<n;i++){
            if(used.count(s[i]))continue;
            
            used.insert(s[i]);
            
            swap(s[i] , s[idx]);
            backtrack(s,idx+1);
            swap(s[i] ,s[idx]);
        }
    }
    vector<string> findPermutation(string &s) {
        // Code here there
        n = s.size();
        ans.clear();
        
        backtrack(s,0);
        return ans;
    }
};
