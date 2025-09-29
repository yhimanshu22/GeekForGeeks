#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        // Max-heap for smaller half
        priority_queue<int> leftMax; 
        // Min-heap for larger half
        priority_queue<int, vector<int>, greater<int>> rightMin; 
        
        vector<double> medians;
        
        for (int num : arr) {
            // Step 1: Insert into max heap
            leftMax.push(num);
            
            // Step 2: Ensure ordering (all left <= all right)
            if (!leftMax.empty() && !rightMin.empty() && leftMax.top() > rightMin.top()) {
                rightMin.push(leftMax.top());
                leftMax.pop();
            }
            
            // Step 3: Balance heap sizes
            if (leftMax.size() > rightMin.size() + 1) {
                rightMin.push(leftMax.top());
                leftMax.pop();
            }
            else if (rightMin.size() > leftMax.size() + 1) {
                leftMax.push(rightMin.top());
                rightMin.pop();
            }
            
            // Step 4: Get median
            if (leftMax.size() == rightMin.size()) {
                double median = (leftMax.top() + rightMin.top()) / 2.0;
                medians.push_back(median);
            }
            else if (leftMax.size() > rightMin.size()) {
                medians.push_back(leftMax.top());
            }
            else {
                medians.push_back(rightMin.top());
            }
        }
        
        return medians;
    }
};
