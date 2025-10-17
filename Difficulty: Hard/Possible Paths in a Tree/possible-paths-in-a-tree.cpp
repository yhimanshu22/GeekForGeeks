class Solution {
public:
    int findParent(int u, vector<int>& parent) {
        if (parent[u] == u) return u;
        return parent[u] = findParent(parent[u], parent);
    }

    void unionSet(int u, int v, vector<int>& parent, vector<long long>& size, long long &totalPaths) {
        int pu = findParent(u, parent);
        int pv = findParent(v, parent);
        if (pu == pv) return;

        // Number of new paths formed
        totalPaths += size[pu] * size[pv];

        // Merge components
        parent[pu] = pv;
        size[pv] += size[pu];
    }

    vector<int> maximumWeight(int n, vector<vector<int>> edges, int q, vector<int> &queries) {
        // Step 1: Sort edges by weight ascending
        sort(edges.begin(), edges.end(), [](auto &a, auto &b){
            return a[2] < b[2];
        });

        // Step 2: Sort queries and store original index
        vector<pair<int,int>> Q;
        for (int i = 0; i < q; i++) Q.push_back({queries[i], i});
        sort(Q.begin(), Q.end());

        vector<int> parent(n+1);
        vector<long long> size(n+1, 1);
        for (int i = 1; i <= n; i++) parent[i] = i;

        vector<long long> ansLL(q);
        long long totalPaths = 0;
        int j = 0;

        // Step 3: Process queries
        for (auto &[limit, idx] : Q) {
            while (j < edges.size() && edges[j][2] <= limit) {
                int u = edges[j][0];
                int v = edges[j][1];
                unionSet(u, v, parent, size, totalPaths);
                j++;
            }
            ansLL[idx] = totalPaths;
        }

        // Step 4: Convert to vector<int> safely
        vector<int> ans(q);
        for (int i = 0; i < q; i++) ans[i] = (int)ansLL[i]; // cast to int

        return ans;
    }
};
