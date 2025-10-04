class Solution {
public:
    int maxProduct(vector<int> &arr) {
        int n = arr.size();
        int maxProd = arr[0];
        int maxEndingHere = arr[0];
        int minEndingHere = arr[0];

        for (int i = 1; i < n; i++) {
          
            maxEndingHere = max(arr[i], arr[i] * maxEndingHere);
            minEndingHere = min(arr[i], arr[i] * minEndingHere);
  if (arr[i] < 0) 
                swap(maxEndingHere, minEndingHere); // flip because of negative

            maxProd = max(maxProd, maxEndingHere);
        }

        return maxProd;
    }
};
