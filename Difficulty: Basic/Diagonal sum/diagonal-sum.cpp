// User function Template for C++

class Solution {
  public:
    int DiagonalSum(vector<vector<int> >& matrix) {
        int n = matrix.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            // primary diagonal
            sum += matrix[i][i];
            // secondary diagonal
            sum += matrix[i][n - i - 1];
        }

        return sum;
    }
};