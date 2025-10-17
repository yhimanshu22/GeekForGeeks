class Solution {
public:
    int countWays(int n, int k) {
        if (n == 0) return 0;
        if (n == 1) return k;
        if (n == 2) return k * k;

        long long same = k;       // ways when last two posts are same (n=2)
        long long diff = k * (k-1); // ways when last two posts are different
        long long total = same + diff;

        for (int i = 3; i <= n; i++) {
            long long new_same = diff; // last two same only if previous were different
            long long new_diff = total * (k-1);
            total = new_same + new_diff;
            same = new_same;
            diff = new_diff;
        }

        return total;
    }
};
