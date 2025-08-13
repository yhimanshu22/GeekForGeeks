// User function Template for C++

class Solution {
  public:
    string binaryAdd(int n, string s) {
        // code here
       int carry = 1; // we are adding '1' to the binary number

        // Traverse from rightmost bit to left
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1' && carry == 1) {
                s[i] = '0'; // 1 + 1 = 0, carry = 1
                carry = 1;
            } 
            else if (s[i] == '0' && carry == 1) {
                s[i] = '1'; // 0 + 1 = 1, carry = 0
                carry = 0;
                break; // No need to continue
            }
        }

        // If carry is still left, we prepend '1'
        if (carry == 1) {
            s = '1' + s;
        }

        return s;
        
        
        
    }
};