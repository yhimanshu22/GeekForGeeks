#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max-heap: pair of (distance, point)
        priority_queue<pair<int, vector<int>>> pq;

        for (auto &p : points) {
            int dist = p[0]*p[0] + p[1]*p[1];  // squared distance
            pq.push({dist, p});
            if (pq.size() > k) pq.pop();        // keep only k closest
        }

        vector<vector<int>> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
