class Solution {
  public:
    vector<int> getTriangle(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        vector<vector<int>> triangle;

        // Push the last row first
        triangle.push_back(arr);

        // Build triangle upwards
        while (arr.size() > 1) {
            vector<int> newRow;
            for (int i = 0; i < (int)arr.size() - 1; i++) {
                newRow.push_back((arr[i] + arr[i + 1]) % MOD);
            }
            triangle.push_back(newRow);
            arr = newRow;
        }

        // Flatten from top to bottom
        vector<int> res;
        for (int i = triangle.size() - 1; i >= 0; i--) {
            for (auto x : triangle[i]) {
                res.push_back(x);
            }
        }
        return res;
    }
};
