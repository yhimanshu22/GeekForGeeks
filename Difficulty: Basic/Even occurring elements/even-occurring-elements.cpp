class Solution {
  public:
    vector<int> findEvenOccurrences(vector<int>& arr) {
        // code here
        vector<int> ans;
        
        unordered_map<int ,int > freq;
        for(int x:arr)freq[x]++;
        unordered_set<int> visited;
        
        for (int x : arr) {
            if (!visited.count(x) && freq[x] % 2 == 0) {
                ans.push_back(x);
                visited.insert(x);
            }
        }
        
        if (ans.empty()) return {-1};
        
        return ans;
    }
};
