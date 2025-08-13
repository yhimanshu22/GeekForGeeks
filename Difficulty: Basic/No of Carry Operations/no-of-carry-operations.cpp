class Solution {
  public:
    long long countCarry(long long A, long long B) {
        // code here
        int carry = 0;
        int cnt = 0;
        
        while( A > 0  || B > 0 ){
            int d1 = A%10;
            int d2 = B%10;
            
            if(d1 + d2 + carry >= 10){
                carry = 1;
                cnt++;
            }else{
                carry = 0;
            }
            
            A/=10;
            B/=10;
        }
        
        return cnt;
        
        
    }
};