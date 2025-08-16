// User function Template for C++

class Solution {
  public:
    vector<vector<int>> swapTriangle(int N, vector<vector<int>> A) {
        // code here
         for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                swap(A[i][j], A[j][i]);
            }
        }
        
        return A;
    }
};