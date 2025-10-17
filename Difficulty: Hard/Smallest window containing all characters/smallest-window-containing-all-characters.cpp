#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    string smallestWindow(string &s, string &p) {
        int n = s.length();
        int m = p.length();

        if (m > n) {
            return "";
        }

        // 1. Target Frequency Map: Stores the required frequency of each char in p.
        map<char, int> p_freq;
        for (char c : p) {
            p_freq[c]++;
        }

        // --- Initialization ---
        
        // Window Frequency Map: Tracks char counts in the current s[L...R] window.
        map<char, int> window_freq;

        // Tracks how many unique characters in p have their required frequency satisfied.
        int formed = 0; 
        
        // Total number of unique characters that must be satisfied.
        int required = p_freq.size();

        // Variables to store the result
        int min_len = n + 1;
        int result_start_index = -1;

        int L = 0; // Left pointer

        // 2. EXPAND: Right pointer (R) moves forward to find a valid window.
        for (int R = 0; R < n; ++R) {
            char c_right = s[R];

            // Add the new character to the window
            window_freq[c_right]++;

            // Check if this character helps satisfy a requirement
            if (p_freq.count(c_right) && window_freq[c_right] == p_freq[c_right]) {
                formed++;
            }

            // 3. CONTRACT: Once the window is valid (formed == required), try to shrink it.
            while (L <= R && formed == required) {
                
                // A. Check and Save Current Minimum Length
                int current_len = R - L + 1;
                if (current_len < min_len) {
                    min_len = current_len;
                    result_start_index = L;
                }

                // B. Prepare to Shrink (remove character at L)
                char c_left = s[L];
                window_freq[c_left]--;

                // C. Check if the window is now invalid
                // If c_left was a required char AND its count drops below the requirement, 
                // the window is no longer valid.
                if (p_freq.count(c_left) && window_freq[c_left] < p_freq[c_left]) {
                    formed--;
                }

                // Move L pointer to the right to shrink the window
                L++;
            }
        }

        // 4. Final Result
        if (result_start_index == -1) {
            return "";
        } else {
            return s.substr(result_start_index, min_len);
        }
    }
};
