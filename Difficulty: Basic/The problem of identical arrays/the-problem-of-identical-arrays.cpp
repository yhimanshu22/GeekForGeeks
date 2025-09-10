class Solution {
  public:
    bool isIdentical(vector<int> &a, vector<int> &b) {
        // Your code goes here.
        if(a.size() != b.size())return false;
        unordered_map<int,int> map;
        
        for(int i:a){
         map[i]++;   
        }
        
        for(int i:b){
            if(map[i] == 0)return false;
            map[i]--;
        }
        
        return true;
    }
};