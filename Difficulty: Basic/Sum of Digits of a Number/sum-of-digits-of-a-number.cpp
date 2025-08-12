class Solution {
  public:
    int sumOfDigits(int n) {
        // Code here
       if(n / 10 == 0)return n; 
        
        
        return n%10 + sumOfDigits(n/10);
    }
};