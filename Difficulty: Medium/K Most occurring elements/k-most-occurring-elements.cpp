// Function to print the k numbers with most occurrences

class Solution {
  public:
    // Function to return the sum of frequencies of k numbers
    // with most occurrences in an array.
    int kMostFrequent(vector<int>& arr, int k) {
        // Your code here
        unordered_map<int, int> freq;

    // Step 1: Count frequency of each element
    for (int num : arr) freq[num]++;

    // Step 2: Store frequencies in a max-heap
    priority_queue<int> pq;
    for (auto &it : freq) pq.push(it.second);

    // Step 3: Sum top k frequencies
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += pq.top();
        pq.pop();
    }

    return sum;
    }
};