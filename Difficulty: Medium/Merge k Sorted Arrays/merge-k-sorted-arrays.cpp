#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        vector<int> result;
        // Min-heap: {value, {array_index, element_index}}
        priority_queue< 
            pair<int, pair<int,int>>, 
            vector<pair<int,pair<int,int>>>, 
            greater<pair<int,pair<int,int>>> 
        > pq;

        // Step 1: push first element of each array into heap
        for(int i = 0; i < K; i++) {
            if(!arr[i].empty())
                pq.push({arr[i][0], {i, 0}});
        }

        // Step 2: extract min and push next element from same array
        while(!pq.empty()) {
            auto [val, idx] = pq.top(); pq.pop();
            int arr_idx = idx.first;
            int ele_idx = idx.second;
            result.push_back(val);

            if(ele_idx + 1 < arr[arr_idx].size()) {
                pq.push({arr[arr_idx][ele_idx + 1], {arr_idx, ele_idx + 1}});
            }
        }

        return result;
    }
};
