// User function Template for C++
class Solution {
  public:
    vector<int> uniqueId(vector<int>& arr) {
        // code
       vector<int> ans;
        unordered_set<int> seen;

        for (int id : arr) {
            if (seen.find(id) == seen.end()) { // not seen before
                ans.push_back(id);
                seen.insert(id);
            }
        }
        return ans;
    }
};