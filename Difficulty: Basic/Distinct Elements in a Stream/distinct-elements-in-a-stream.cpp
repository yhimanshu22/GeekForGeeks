class Solution {
  public:
    vector<int> getDistinct(vector<int> &arr) {
        // code here
        unordered_map<int,int> freq;
        
        vector<int> ans;
        
        for(int x:arr){
            if(x>0){
                freq[x]++;
            }else{
                int val = -x;
                if(freq.find(val) != freq.end()){
                    freq[val]--;
                    if(freq[val]==0){
                        freq.erase(val);
                    }
                }
                
            }
            
            ans.push_back(freq.size());
        }
        
        return ans;
        
    }
};