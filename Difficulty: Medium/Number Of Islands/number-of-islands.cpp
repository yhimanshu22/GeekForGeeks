class Solution {
public:
    int find(vector<int>& parent, int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent, parent[x]); // Path compression
    }
    
    void unionSet(vector<int>& parent, int x, int y) {
        int px = find(parent, x);
        int py = find(parent, y);
        if (px != py) parent[px] = py;
    }

    vector<int> numOfIslands(int n, int m, vector<vector<int>>& operators) {
        vector<int> parent(n*m, -1); // -1 means water
        vector<int> ans;
        int islands = 0;
        
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        for (auto& op : operators) {
            int r = op[0], c = op[1];
            int idx = r * m + c;

            if (parent[idx] != -1) {
                ans.push_back(islands); // Already land, no change
                continue;
            }

            parent[idx] = idx; // Make this cell land
            islands++;

            for (int k = 0; k < 4; k++) {
                int nr = r + dx[k];
                int nc = c + dy[k];
                int nidx = nr * m + nc;

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && parent[nidx] != -1) {
                    int p1 = find(parent, idx);
                    int p2 = find(parent, nidx);
                    if (p1 != p2) {
                        unionSet(parent, p1, p2);
                        islands--; // Merge reduces island count
                    }
                }
            }

            ans.push_back(islands);
        }

        return ans;
    }
};
