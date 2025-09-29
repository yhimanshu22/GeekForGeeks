#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> pq; // min-heap

        for(int i = 0; i < n; i++) {
            pq.push(arr[i]);

            if(pq.size() > k) pq.pop();

            if(pq.size() < k)
                ans.push_back(-1);
            else
                ans.push_back(pq.top());
        }

        return ans;
    }
};
