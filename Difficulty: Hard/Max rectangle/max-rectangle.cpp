class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        heights.push_back(0); // sentinel

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                int w = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * w);
            }
            st.push(i);
        }
        return maxArea;
    }

    int maxArea(vector<vector<int>> &mat) {
        if (mat.empty()) return 0;
        int m = mat.size(), n = mat[0].size();
        vector<int> heights(n, 0);
        int maxAreaResult = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                heights[j] = (mat[i][j] == 0) ? 0 : heights[j] + 1;
            }
            maxAreaResult = max(maxAreaResult, largestRectangleArea(heights));
        }

        return maxAreaResult;
    }
};
