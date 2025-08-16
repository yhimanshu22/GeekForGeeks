// User function Template for C++

class Solution {
  public:
    int sortedCount(int N, int M, vector<vector<int>> Mat) {
        // code here
         int count = 0;

        for (int i = 0; i < N; i++) {
            bool increasing = true, decreasing = true;

            for (int j = 1; j < M; j++) {
                if (Mat[i][j] <= Mat[i][j - 1]) increasing = false;
                if (Mat[i][j] >= Mat[i][j - 1]) decreasing = false;
            }

            if (increasing || decreasing) count++;
        }

        return count;
    }
};