// User function template for C++

class Solution {
  public:
    int diagonalSumDifference(int N, vector<vector<int>> Grid) {
        // code here
          // code here
        int prim = 0;
        int sec = 0;
        
        for(int i=0;i<N;i++){
            prim += Grid[i][i];
            sec += Grid[i][N-1-i];
        }
        
        return abs(prim - sec);
    }
};