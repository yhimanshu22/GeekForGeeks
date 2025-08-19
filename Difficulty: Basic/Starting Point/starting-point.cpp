// User function Template for C++

class Solution {
  public:
    vector<int> findStartingPoint(int x, int y, vector<vector<int>> pathCoordinates) {
        // Code here
         for (auto &p : pathCoordinates) {
            x -= p[0];
            y -= p[1];
        }
        return {x, y};
    }
};