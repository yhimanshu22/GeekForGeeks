// User function Template for C++

class Solution {
  public:
    int sumOfRowCol(int N, int M, vector<vector<int>> A) {
       int limit = min(N, M);

        for (int i = 0; i < limit; i++) {
            int rowSum = 0, colSum = 0;

            // Sum of i-th row
            for (int j = 0; j < M; j++) {
                rowSum += A[i][j];
            }

            // Sum of i-th column
            for (int j = 0; j < N; j++) {
                colSum += A[j][i];
            }

            if (rowSum != colSum) {
                return 0; // mismatch found
            }
        }

        return 1; // all matched
        
    }
};