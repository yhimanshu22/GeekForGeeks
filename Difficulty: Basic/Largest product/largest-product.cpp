/*You are required to complete the function*/
class Solution {
  public:
    int findMaxProduct(vector<int>& arr, int k) {
           int n = arr.size();
        if (n < k) return -1; // Not enough elements
        
        int maxProduct = 0;
        
        for (int i = 0; i <= n - k; i++) {
            int product = 1;
            for (int j = i; j < i + k; j++) {
                product *= arr[j];
            }
            maxProduct = max(maxProduct, product);
        }
        
        return maxProduct;
    }
};