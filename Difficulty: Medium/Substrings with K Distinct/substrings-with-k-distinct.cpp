// User function Template for C++

class Solution {
 public:
    // Function to count the number of substrings with EXACTLY k distinct characters.
    int countSubstr(string& s, int k) {
        
        // Helper function (lambda) to count substrings with AT MOST 'max_k' distinct characters.
        auto count_at_most_k = [&](int max_k) -> long long {
            if (max_k <= 0) return 0; // Cannot form any substring with 0 or negative distinct characters

            int n = s.length();
            long long count = 0;
            
            // Frequency array for the current window [L, R] (assuming lowercase 'a'-'z')
            vector<int> freq(26, 0); 
            int distinct_count = 0;
            int L = 0; // Left pointer
            
            for (int R = 0; R < n; ++R) {
                int char_index = s[R] - 'a';

                // 1. EXPAND: Add the current character s[R] to the window
                if (freq[char_index] == 0) {
                    distinct_count++;
                }
                freq[char_index]++;
                
                // 2. CONTRACT: Shrink the window (move L) if distinct count exceeds max_k
                while (distinct_count > max_k) {
                    int left_index = s[L] - 'a';

                    freq[left_index]--;
                    if (freq[left_index] == 0) {
                        distinct_count--;
                    }
                    L++; // Move the left pointer
                }
                
                // 3. COUNT: When the window s[L...R] is valid (has <= max_k distinct chars),
                // all substrings ending at R and starting from L to R are valid.
                // Number of valid substrings ending at R is (R - L + 1).
                count += (R - L + 1);
            }
            
            return count;
        };

        // Apply Inclusion-Exclusion Principle:
        // Count(Exactly k) = Count(<= k) - Count(<= k-1)
        long long count_k = count_at_most_k(k);
        long long count_k_minus_1 = count_at_most_k(k - 1);
        
        return (int)(count_k - count_k_minus_1);
    }
};