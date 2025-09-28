class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // Your code here
        priority_queue<int,vector<int> ,greater<int>> pq;
        
        for(int n:arr){
            pq.push(n);
            if(pq.size() > k)pq.pop();
        }
        
        vector<int> res;
        while(!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }
        
        // currently ascending → reverse to get k largest in descending order
        reverse(res.begin(), res.end());
        
        return res;
            
    }
};