#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        vector<int> ans;
        
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        
        // Max-heap: {sum, {i,j}}
        priority_queue<pair<int, pair<int,int>>> pq;
        set<pair<int,int>> visited;
        
        pq.push({a[0]+b[0], {0,0}});
        visited.insert({0,0});
        
        while(!pq.empty() && ans.size() < k) {
            auto top = pq.top(); pq.pop();
            int sum = top.first;
            int i = top.second.first;
            int j = top.second.second;
            
            ans.push_back(sum);
            
            // Push next pair (i+1,j)
            if(i+1 < n && !visited.count({i+1,j})) {
                pq.push({a[i+1]+b[j], {i+1,j}});
                visited.insert({i+1,j});
            }
            
            // Push next pair (i,j+1)
            if(j+1 < n && !visited.count({i,j+1})) {
                pq.push({a[i]+b[j+1], {i,j+1}});
                visited.insert({i,j+1});
            }
        }
        
        return ans;
    }
};
