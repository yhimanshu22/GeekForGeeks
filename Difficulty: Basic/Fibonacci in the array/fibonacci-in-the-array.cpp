class Solution {
  public:
    int countFibonacciNumbers(vector<long long>& arr) {
        // code here
          int count = 0;
        for (int num : arr) {
            if (isFibo(num)) count++;
        }
        return count;
    }
    
     bool isPerfectSquare(long long x) {
        long long s = sqrt(x);
        return (s * s == x);
    }

    // Function to check if a number is Fibonacci
    bool isFibo(int n) {
        return isPerfectSquare(1LL * 5 * n * n + 4) || 
               isPerfectSquare(1LL * 5 * n * n - 4);
    }
};
