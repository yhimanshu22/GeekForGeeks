#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countCoPrime(const vector<int>& arr) {
        int cnt = 0;
        int n = arr.size();
        
        for (int i = 0; i < n - 1; i++) { 
            if (gcd(arr[i], arr[i + 1]) != 1) { // check if not co-prime
                cnt++;
            }
        }
        
        return cnt;
    }
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

};
