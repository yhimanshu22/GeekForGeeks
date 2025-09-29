#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        int n = start.size();
        if (n == 0) return 0;

        // min-heap ordered by finish time
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        // push {finish, start}
        for (int i = 0; i < n; i++) {
            pq.push({finish[i], start[i]});
        }

        int count = 0;
        int lastFinish = -1;

        while (!pq.empty()) {
            auto [f, s] = pq.top(); pq.pop();
            if (s > lastFinish) {
                count++;
                lastFinish = f;
            }
        }
        return count;
    }
};
