class Solution {
public:
    int n;
    vector<int> parent, size;

    int findParent(int x) {
        if (parent[x] == x) return x;
        return parent[x] = findParent(parent[x]);
    }

    void unionSet(int x, int y) {
        int px = findParent(x);
        int py = findParent(y);
        if (px == py) return;
        parent[px] = py;
        size[py] += size[px];
    }

    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        parent.resize(n*n);
        size.resize(n*n, 1);

        for (int i = 0; i < n*n; i++) parent[i] = i;

        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        // Step 1: Union all existing 1s
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                int id1 = i*n + j;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] == 1) {
                        int id2 = ni*n + nj;
                        unionSet(id1, id2);
                    }
                }
            }
        }

        int ans = 0;
        // Step 2: Check flipping each 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) continue;
                unordered_set<int> seen;
                int total = 1; // flip this 0 to 1
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] == 1) {
                        int p = findParent(ni*n + nj);
                        if (!seen.count(p)) {
                            total += size[p];
                            seen.insert(p);
                        }
                    }
                }
                ans = max(ans, total);
            }
        }

        // Step 3: If no 0 exists, largest island is all 1s
        for (int i = 0; i < n*n; i++) ans = max(ans, size[findParent(i)]);

        return ans;
    }
};
