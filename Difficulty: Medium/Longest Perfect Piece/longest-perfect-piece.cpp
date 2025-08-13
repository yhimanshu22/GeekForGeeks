class Solution {
  public:
    int longestPerfectPiece(int arr[], int N) {
        // code here
         map<int,int> freq;
    int i = 0, maxLen = 0;
    

    for (int j = 0; j < N; j++) {
        freq[arr[j]]++;

        // shrink window if difference > 1
        while (freq.rbegin()->first - freq.begin()->first > 1) {
            freq[arr[i]]--;
            if (freq[arr[i]] == 0) freq.erase(arr[i]);
            i++;
        }

        maxLen = max(maxLen, j - i + 1);
    }

    return maxLen;
        
    }
};