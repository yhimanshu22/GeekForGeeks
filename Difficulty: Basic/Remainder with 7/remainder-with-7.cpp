class Solution {
  public:
    /*You are required to complete this method */
    int remainderWith7(string n) {
        // Your code here
        int ans = 0;
        
        for(char c : n){
            int dig = c - '0';
            ans = (ans*10 + dig)%7;
        }
        return ans;
    }
};