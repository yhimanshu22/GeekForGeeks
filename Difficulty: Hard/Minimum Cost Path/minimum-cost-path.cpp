#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minimumCostPath(vector<vector<int>>& grid) {
        int N = grid.size();
        vector<vector<int>> dist(N, vector<int>(N, INT_MAX));
        dist[0][0] = grid[0][0];

        // Min-heap: {cost_so_far, {i, j}}
        priority_queue<pair<int, pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> pq;
        pq.push({grid[0][0], {0,0}});

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while(!pq.empty()) {
            auto [cost, pos] = pq.top(); pq.pop();
            int i = pos.first, j = pos.second;

            // If we reached bottom-right, return cost
            if(i == N-1 && j == N-1) return cost;

            for(int k = 0; k < 4; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];

                if(ni >= 0 && ni < N && nj >= 0 && nj < N) {
                    int newCost = cost + grid[ni][nj];
                    if(newCost < dist[ni][nj]) {
                        dist[ni][nj] = newCost;
                        pq.push({newCost, {ni, nj}});
                    }
                }
            }
        }

        return dist[N-1][N-1];
    }
};
