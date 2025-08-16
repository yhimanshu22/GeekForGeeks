class Solution {
  public:
    bool multiplyMatrix(int mat1[4][4], int mat2[4][4], int res[4][4]) {
        // Calculate multiplication
        int result[4][4] = {0};

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                result[i][j] = 0;
                for (int k = 0; k < 4; k++) {
                    result[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }

        // Compare with res
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (result[i][j] != res[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};
