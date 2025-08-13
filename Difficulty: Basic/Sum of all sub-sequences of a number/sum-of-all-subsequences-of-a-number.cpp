// User function template for C++
class Solution {
  public:

    int subsequenceSum(string s) {
        // Your code goes here
       long long  sum = 0;
       int n = s.length();
       
       for(auto c:s){
           sum += c - '0';
       }
       
       long long power = 1LL << (n-1);
       
       return sum*power;
       
       
    }
};