//Back-end complete function Template for C++

class Solution {
  public:
    int countZeros(vector<vector<int>> A) {
        // code here
        int cnt = 0;
        int N = A.size();
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(A[i][j] == 0)cnt++;
            }
        }
        
        return cnt;
    }
};