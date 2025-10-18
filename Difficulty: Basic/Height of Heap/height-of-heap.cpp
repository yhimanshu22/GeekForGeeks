#include <cmath>

class Solution {
public:
    int heapHeight(int n, int arr[]) {
        if (n == 1) return 1;           // Special case
        return (int)floor(log2(n));     // Height of complete binary heap
    }
};
