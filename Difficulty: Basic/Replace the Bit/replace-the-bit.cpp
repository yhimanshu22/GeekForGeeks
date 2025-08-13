class Solution {
  public:
    int replaceBit(int n, int k) {
        // code here.
        int length = (int)log2(n) + 1;
        int pos_right = length - k;
        
        if((n >> pos_right) & 1){
            n = n & ~(1 << pos_right);
        }
        
        return n;
    }
};