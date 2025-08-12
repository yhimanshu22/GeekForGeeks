// User function Template for C++
class Solution {
public:
    long long gfSeriesUtil(int n) {
        if (n == 1) return 0; // Base case: G(1) = 0
        if (n == 2) return 1; // Base case: G(2) = 1
        return gfSeriesUtil(n-2) * gfSeriesUtil(n-2) - gfSeriesUtil(n-1); // Recursive case
    }
    
    void gfSeries(int N) {
        if (N < 1) return; // Handle invalid input
        for (int i = 1; i <= N; i++) {
            cout << gfSeriesUtil(i) << " "; // Print each term using recursive function
        }
        cout << endl; // New line after series
    }
};