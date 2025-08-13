class Solution {
  public:

    int LastIndex(string s, char p) {
        // complete the function here
      
        int n = s.length();
        
        for(int i = n -1 ;i >=0;i--){
            if(s[i] == p){
                return i;
            }
        }
        return -1;
    }
};