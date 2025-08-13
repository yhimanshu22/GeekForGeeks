

class Solution {
  public:
    long long int equalPairs(string s) {
        // code here.
        vector<int> freq(256,0);
        int cnt = 0;
        for(char c : s){
            freq[c]++;
        }
        
        for(int f:freq){
            if(f > 0){
                cnt += f*f;
            }
        }
        
        return cnt;
            
    }
};