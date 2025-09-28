class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        // Push all ropes into min-heap
        for(long long rope : arr) {
            pq.push(rope);
        }

        long long totalCost = 0;

        while(pq.size() > 1) {
            long long a = pq.top(); pq.pop();
            long long b = pq.top(); pq.pop();

            long long cost = a + b;
            totalCost += cost;

            pq.push(cost);
        }

        return totalCost;
    }
};