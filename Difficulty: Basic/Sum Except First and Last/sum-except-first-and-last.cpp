class Solution {
  public:
    /*You are required to complete this method*/
    int sumExceptFirstLast(vector<int>& arr) {
        // Your code here
        int n = arr.size();

        int sum = 0;
        for (int i = 1; i < n - 1; i++) {
            sum += arr[i];
        }
        return sum;
    }
};