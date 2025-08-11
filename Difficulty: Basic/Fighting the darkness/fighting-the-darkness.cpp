// User function template for C++

class Solution {
  public:
    int maxDays(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        sort(arr.begin() , arr.end() , greater<int>());
        
        return arr[0];
    }
};