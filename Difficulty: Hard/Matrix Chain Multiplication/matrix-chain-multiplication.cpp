#include <vector>
#include <algorithm>
#include <climits> // For INT_MAX

using namespace std;

class Solution {
public:
    int matrixMultiplication(vector<int>& arr) {
        int N = arr.size();
        
        // Number of matrices is N-1. Matrix M_i is arr[i-1] x arr[i].
        int num_matrices = N - 1;
        
        // dp[i][j] stores the minimum multiplications for matrices M_i through M_j.
        // We use (N) x (N) size to utilize 1-based indexing from 1 to num_matrices.
        // Initialize with 0s. Use long long for dp to prevent multiplication overflow.
        vector<vector<long long>> dp(N, vector<long long>(N, 0)); 
        
        // L is the chain length (length = 2 means M_i * M_{i+1})
        for (int L = 2; L <= num_matrices; ++L) {
            
            // i is the starting matrix index (1-based)
            for (int i = 1; i <= num_matrices - L + 1; ++i) {
                int j = i + L - 1; // j is the ending matrix index
                
                dp[i][j] = LLONG_MAX; // Initialize with maximum possible value
                
                // k is the split point (M_i...M_k) * (M_{k+1}...M_j)
                for (int k = i; k < j; ++k) {
                    
                    // Cost of current split:
                    // 1. Cost to multiply M_i through M_k (dp[i][k])
                    // 2. Cost to multiply M_{k+1} through M_j (dp[k+1][j])
                    // 3. Cost of the final multiplication (arr[i-1] * arr[k] * arr[j])
                    
                    long long cost = dp[i][k] + dp[k+1][j] + 
                                     (long long)arr[i-1] * arr[k] * arr[j];
                    
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }
        
        // The result is dp[1][num_matrices]
        return (int)dp[1][num_matrices];
    }
};