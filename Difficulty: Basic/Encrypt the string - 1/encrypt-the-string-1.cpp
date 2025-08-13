

class Solution {
  public:
    string encryptString(string s) {
        // code here
        string ans = "";
        int n = s.length();
        
        for(int i=0;i<n;){
         char ch = s[i];
         int cnt = 0;
         
         while(i < n && s[i] == ch){
             cnt++;
             i++;
         }
         
         ans += ch + to_string(cnt);
         }
         
         reverse(ans.begin() , ans.end());
         
         return ans;
    }
};