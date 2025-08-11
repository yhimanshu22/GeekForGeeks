// User function Template for C++
class Solution {
  public:
    int isSumPalindrome(int n) {
      if (pal(n)) return n;
        long long cur = n;
        for (int i = 0; i < 5; ++i) {
            cur = rev(cur);
            if (pal(cur)) return (int)cur;
        }
        return -1;
    }
    
    bool pal(int n){
      string s = to_string(n);
      string t =s;
      reverse(t.begin() , t.end());
      return t == s;
    }
    
    int rev(int n){
      string s = to_string(n);
        reverse(s.begin(), s.end());
        int revNum = stoi(s);
        return revNum + n;
    }
};